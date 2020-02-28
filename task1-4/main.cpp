#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main() 
{

	cv::Mat srcMat = imread("D:\\UpupooResource\\2000222879\\test.jpg");
	cv::Mat deepMat;
	cv::Mat shallowMat;
	int height = srcMat.rows; //行数
	int width = srcMat.cols; //每行元素的总元素数量
	shallowMat = srcMat;
	srcMat.copyTo(deepMat);
	uchar threshold = 100;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2]) / 3;
			//average和threshold比较
			if (average > threshold)
				average = 255;
			else
				average = 0;
			//赋值给像素的三个通道
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
		}
	}
	imshow("shallow", shallowMat);
	imshow("deep", deepMat);
	waitKey(0);
	return 0;
}
