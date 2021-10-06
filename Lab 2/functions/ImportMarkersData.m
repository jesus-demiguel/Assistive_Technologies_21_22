function [Markers] = ImportMarkersData(FileName)
% Arrange and import marker information from Motive
% Input - FileName: Name of the file (string)
% Output - XYZ Markers info
FullFile = textread(FileName,'%s','delimiter',',');
DataStart = length(textread(FileName,'%s','delimiter',',',...
    'headerlines',1));
NoMarkers = length(textread(FileName,'%s','delimiter',',',...
    'headerlines',3));
Data = textread(FileName,'%f','delimiter',',','headerlines',7);

Header = FullFile(1:length(FullFile)-DataStart);
FrameRate = str2double(Header(6));
MarkersL = FullFile(length(FullFile)-DataStart+3:length(FullFile)-NoMarkers);
NMarkers = length(MarkersL)/3;

c = 1;
for i=1:(NMarkers*3+2):length(Data)
    TFrames(c) = Data(i);
    c = c+1;
end
NFrames = length(TFrames);
c = 1;
for i=2:(NMarkers*3+2):length(Data)
    Time(c) = Data(i);
    c = c+1;
end

DataL = textread(FileName,'%s','delimiter',',','headerlines',3);
DataL = DataL(3:(NMarkers*3)+2);
c = 1;
for l=1:3:length(DataL)
    Labels(c,1) = DataL(l);
    c = c+1;
end
Labels=strrep(Labels,'MarkerSet:','');
Labels=strrep(Labels,'MarkerSet_','');

Markers = zeros(NFrames,NMarkers,3);
Data3D = zeros((NMarkers*3)+2,NFrames);
for i=1:length(Data)
    Data3D(i) = Data(i);
end
Data3D = Data3D';
for f=1:NFrames
    c = 1;
    for x=3:3:(NMarkers*3)+2
        current_label = cell2mat(Labels(c));
        current_index = str2num(current_label(8:end));
        Markers(f,current_index,1) = Data3D(f,x);
        Markers(f,current_index,3) = Data3D(f,x+1);
        Markers(f,current_index,2) = -1*Data3D(f,x+2);
        c = c+1;
    end
end


answer_animation = questdlg('Do you want to see an animation of the markers?', ...
                            'Markers Animation','Yes','No','Exit');
if strcmp(answer_animation,'Yes') 
    AnimateMarkers(Markers);
end
