/*----------------------------------------------
* Usage:
* example_tracking_kcf <video_name>
*
* example:
* example_tracking_kcf Bolt/img/%04.jpg
* example_tracking_kcf faceocc2.webm
*--------------------------------------------------*/

//KCF Object Tracking

#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/ocl.hpp>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
using namespace cv;

#define DEBUG 

class BoxExtractor {
public:
	Rect2d extract(Mat img);
	Rect2d extract(const std::string& windowName, Mat img, bool showCrossair = true);

	struct handlerT {
		bool isDrawing;
		Rect2d box;
		Mat image;

		// initializer list
		handlerT() : isDrawing(false) {};
	}params;

private:
	static void mouseHandler(int event, int x, int y, int flags, void *param);
	void opencv_mouse_callback(int event, int x, int y, int, void *param);
};

int main(int argc, char** argv) {
	// show help
	if (argc < 2) {
		cout <<
			" Usage: example_tracking_kcf <video_name>\n"
			" examples:\n"
			" example_tracking_kcf Bolt/img/%04.jpg\n"
			" example_tracking_kcf faceocc2.webm\n"
			<< endl;
		return 0;
	}

	double track_time = 0;
	unsigned int frame_cnt = 0;
	// ROI selector
	BoxExtractor box;

	// create the tracker
	Ptr<Tracker> tracker = Tracker::create("TLD");//KCF TLD MIL

												  // set input video
	std::string video = argv[1];
	VideoCapture cap(video);

	Mat frame;

	// get bounding box
	cap >> frame;
	Rect2d roi = box.extract("tracker", frame);

	//roi = Rect(215, 145, 19, 33);//woman
	//roi = Rect(223, 243, 49, 53); //Human2
	//roi = Rect(147, 98, 36, 61); //pedestrian3
	//roi = Rect(140, 115, 97, 56); //car
	//roi = { 102 , 235, 24, 83 };//human4 global
	//roi = { 103 , 269, 18, 22 };//human4 local
	//roi = { 103 , 285, 22, 36 };//VID_20170419_103455
	//roi = { 323 , 417, 15, 38 };//human5
	//roi = { 194 , 86, 42, 20 };//RedTeam
	//roi = Rect{ 139 , 146, 46, 76 };//Doll
	//roi = { 285, 142, 42, 49 };//Boy
	roi = Rect(246,	226, 94, 114);
	//roi = Rect(288, 143, 35, 42);
	//quit if ROI was not selected
	if (roi.width == 0 || roi.height == 0)
		return 0;

	// initialize the tracker
	tracker->init(frame, roi);

#ifdef DEBUG
	//show the results
	cout << "VIDEO source resolution is : " << frame.cols << " * " << frame.rows << endl;
	cout << "ROI SIZE is : " << roi.width << " * " << roi.height << endl;
#endif


	// do the tracking
	printf("Start the tracking process, press ESC to quit.\n");
	for (;; ) {
#ifdef DEBUG
		int64 start = cvGetTickCount();
#endif

#ifdef DEBUG
		int64 GFTTtimestart = cvGetTickCount();
#endif
		// get frame from the video
		cap >> frame;

		// stop the program if no more images
		if (frame.rows == 0 || frame.cols == 0)
			break;

		// update the tracking result
		tracker->update(frame, roi);


		// save ROI data
		ofstream fout("roi.txt",ios::app);
		fout << roi.x << "," << roi.y << "," << roi.width << "," << roi.height << endl;

		fout << flush;
		fout.close();

		double GFTTtime = (cvGetTickCount() - GFTTtimestart) / (cvGetTickFrequency() * 1000);
		cout << "Current tracking performance: " << (1000.0 / GFTTtime) << "fps" << endl;
		track_time += GFTTtime;
		frame_cnt++;
		// draw the tracked object
		rectangle(frame, roi, Scalar(255, 0, 0), 2, 1);

		// show image with the tracked object
		imshow("tracker", frame);

		//quit on ESC button
		if (waitKey(1) == 27)break;		//cvWaitKey(k) or waitKey(k)中，k的单位是毫秒，一般在显示图像时，每秒显示27、28帧的时候，人眼看到的视频是流畅的
	}
#ifdef DEBUG
	//show the results
	cout << "Average Tracking time is : " << track_time / frame_cnt << "ms" << endl;
#endif

}

void BoxExtractor::mouseHandler(int event, int x, int y, int flags, void *param) {
	BoxExtractor *self = static_cast<BoxExtractor*>(param);
	self->opencv_mouse_callback(event, x, y, flags, param);
}

void BoxExtractor::opencv_mouse_callback(int event, int x, int y, int, void *param) {
	handlerT * data = (handlerT*)param;
	switch (event) {
		// update the selected bounding box
	case EVENT_MOUSEMOVE:
		if (data->isDrawing) {
			data->box.width = x - data->box.x;
			data->box.height = y - data->box.y;
		}
		break;

		// start to select the bounding box
	case EVENT_LBUTTONDOWN:
		data->isDrawing = true;
		data->box = cvRect(x, y, 0, 0);
		break;

		// cleaning up the selected bounding box
	case EVENT_LBUTTONUP:
		data->isDrawing = false;
		if (data->box.width < 0) {
			data->box.x += data->box.width;
			data->box.width *= -1;
		}
		if (data->box.height < 0) {
			data->box.y += data->box.height;
			data->box.height *= -1;
		}
		break;
	}
}

Rect2d BoxExtractor::extract(Mat img) {
	return extract("Bounding Box Extractor", img);
}

Rect2d BoxExtractor::extract(const std::string& windowName, Mat img, bool showCrossair) {

	int key = 0;

	// show the image and give feedback to user
	imshow(windowName, img);
	printf("Select an object to track and then press SPACE/BACKSPACE/ENTER button!\n");

	// copy the data, rectangle should be drawn in the fresh image
	params.image = img.clone();

	// select the object
	setMouseCallback(windowName, mouseHandler, (void *)&params);

	// end selection process on SPACE (32) BACKSPACE (27) or ENTER (13)
	while (!(key == 32 || key == 27 || key == 13)) {
		// draw the selected object
		rectangle(
			params.image,
			params.box,
			Scalar(255, 0, 0), 2, 1
		);

		// draw cross air in the middle of bounding box
		if (showCrossair) {
			// horizontal line
			line(
				params.image,
				Point((int)params.box.x, (int)(params.box.y + params.box.height / 2)),
				Point((int)(params.box.x + params.box.width), (int)(params.box.y + params.box.height / 2)),
				Scalar(255, 0, 0), 2, 1
			);

			// vertical line
			line(
				params.image,
				Point((int)(params.box.x + params.box.width / 2), (int)params.box.y),
				Point((int)(params.box.x + params.box.width / 2), (int)(params.box.y + params.box.height)),
				Scalar(255, 0, 0), 2, 1
			);
		}

		// show the image bouding box
		imshow(windowName, params.image);

		// reset the image
		params.image = img.clone();

		//get keyboard event
		key = waitKey(1);
	}
	
	return params.box;
}
