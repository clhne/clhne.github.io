function [ success_rate, OverlapRatio ] = success_plot( positions, ground_truth )
% positions and ground_truth format: [x,y,w,h] of the top-left point of the
% bounding box


Ratio = bboxOverlapRatio(positions, ground_truth);
OverlapRatio = diag(Ratio);
threshold = [0.02:0.02:1];
N = size(threshold,2);
success_rate = zeros(N,1);
for i = 1:N
    success_rate(i) = nnz(OverlapRatio >= threshold(i)) / numel(OverlapRatio);
end
grid on;
		plot(success_rate,threshold, 'k-', 'LineWidth',2)
		xlabel('Overlap threshold'), ylabel('Success rate')
end
        
      
        


