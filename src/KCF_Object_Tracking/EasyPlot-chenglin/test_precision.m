%This m file is created by Mr. Sushil Pratap Bharati on May 6, 2016 to 
%plot precision curve for tracking algorithm. 
% Input are two text files and the text format is x1,y1,x2,y2(starting from 
% top left corner of the bounding box)
clear;
A = []; B = []; C = []; D = [];
fileID1 = fopen('KCF_ROI.txt','r'); %output file
fileID2 = fopen('groundtruth_rect.txt','r'); %ground truth file

%对比数据
fileID3 = fopen('LCtracker_result.txt','r');
fileID4 = fopen('TLD_ROI.txt','r');

tline1 = fgetl(fileID1);
tline2 = fgetl(fileID2);

tline3 = fgetl(fileID3);
tline4 = fgetl(fileID4);

while (ischar(tline1))
    C1 = textscan (tline1,'%d,%d,%d,%d');
    C2 = textscan (tline2,'%d,%d,%d,%d');
    C3 = textscan (tline3,'%d,%d,%d,%d');
    C4 = textscan (tline3,'%d,%d,%d,%d');
    
    M1 = double (C1{1}) + ((double(C1{3}) - double(C1{1}))/2.0);
    N1 = double (C1{2}) + ((double(C1{4}) - double(C1{2}))/2.0);
    M2 = double (C2{1}) + ((double(C2{3}) - double(C2{1}))/2.0);
    N2 = double (C2{2}) + ((double(C2{4}) - double(C2{2}))/2.0);
    M3 = double (C3{1}) + ((double(C3{3}) - double(C3{1}))/2.0);
    N3 = double (C3{2}) + ((double(C3{4}) - double(C3{2}))/2.0);
    M4 = double (C4{1}) + ((double(C4{3}) - double(C4{1}))/2.0);
    N4 = double (C2{2}) + ((double(C4{4}) - double(C4{2}))/2.0);
    
    Z1 = [M1 N1];
    Z2 = [M2 N2];
    Z3 = [M3 N3];
    Z4 = [M4 N4];
    
    A = vertcat (A,Z1);  
    B = vertcat (B,Z2);
    C = vertcat (C,Z3);
    D = vertcat (D,Z4);
    
    tline1 = fgetl(fileID1);
    tline2 = fgetl(fileID2);
    tline3 = fgetl(fileID3);
    tline4 = fgetl(fileID4);
end
clearvars -except A B C D;
precision_plots(A,B,1);

%对比曲线
hold on
precision_plotss(C,B,1);
hold on
precision_plotsss(D,B,1);
legend('KCF','Lc-tracker','TLD','Location','NorthEast');
% legend('KCF','Lc-tracker','TLD','Location','NorthEastOutside');
