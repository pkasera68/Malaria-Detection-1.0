import cv2,os
import numpy as np
import csv
import glob

#define the label ,images of which you want to process.
label = "Parasitized"
#here, glob() will return an array of all pathnames mathching the specified pattern..
dirList = glob.glob("cell_images/"+label+"/*.png")
#open will open the csv file to store data.
file = open("csv/dataset.csv","a")
# traversing in the list of pathnames, and processing each image ,extracting features and store in csv file.
#for loop starts
for img_path in dirList:
	im = cv2.imread(img_path)
	im = cv2.GaussianBlur(im,(5,5),2)
	im_gray = cv2.cvtColor(im,cv2.COLOR_BGR2GRAY)
	ret,thresh = cv2.threshold(im_gray,127,255,0)
	contours,_ = cv2.findContours(thresh,1,2)
	file.write(label)
	file.write(",")

	for i in range(5):
		try:
			area = cv2.contourArea(contours[i])
			file.write(str(area))
		except:
			file.write("0")

		file.write(",")

	file.write("\n")

#for loop ends.