%This m file is created by Mr. Sushil Pratap Bharati on May 6, 2016 to 
%plot success curve for tracking algorithm. 
% Input are two text files and the text format is x1,y1,x2,y2(starting from 
% top left corner of the bounding box)
clear;
A=[]; B =[];C=[];
fileID1 = fopen('KCF_ROI.txt','r'); %output file
fileID2 = fopen('groundtruth_rect.txt','r'); %ground truth file
fileID3 = fopen('LCtracker_result.txt','r'); 

tline1 = fgetl(fileID1);
tline2 = fgetl(fileID2);
tline3 = fgetl(fileID3);

while (ischar(tline1))
    C1 = textscan (tline1,'%d,%d,%d,%d');
    C2 = textscan (tline2,'%d,%d,%d,%d');
    C3 = textscan (tline3,'%d,%d,%d,%d');
	
    w1 = double(C1{3}) - double(C1{1});
    h1 = double(C1{4}) - double(C1{2});
    w2 = double(C2{3}) - double(C2{1});
    h2 = double(C2{4}) - double(C2{2});
    w3 = double(C3{3}) - double(C3{1});
    h3 = double(C3{4}) - double(C3{2});
	
    Z1 = [C1{1} C1{2} w1 h1];
    Z2 = [C2{1} C2{2} w2 h2];
    Z3 = [C3{1} C3{2} w3 h3];
	
    A = vertcat (A,Z1);  
    B = vertcat (B,Z2);
    C = vertcat (C,Z3);
	
    tline1 = fgetl(fileID1);
    tline2 = fgetl(fileID2);
    tline3 = fgetl(fileID3);
end
clearvars -except A B C;
success_plots(A,B);
