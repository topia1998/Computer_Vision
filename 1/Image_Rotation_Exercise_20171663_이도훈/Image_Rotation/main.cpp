#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;


cv::Mat problem_a_rotate_forward(cv::Mat img, double angle){
	cv::Mat output;
	//////////////////////////////////////////////////////////////////////////////
	//                         START OF YOUR CODE                               //
	//////////////////////////////////////////////////////////////////////////////
	int width = img.size().width; //가로
	int height = img.size().height; //세로
	const double cosB = cos(((angle) * CV_PI / 180));
	const double sinB = sin(((angle) * CV_PI / 180));
	int w = abs(width * cosB + height * sinB);
	int h = abs(width * sinB + height * cosB);
	output.create(w, h, img.type());
	output.setTo(0);
	int Center_j, Center_i;
	Center_i = (int)img.rows / 2;
	Center_j = (int)img.cols / 2;

	int Center_dsti, Center_dstj;
	Center_dsti = (int)output.rows / 2;
	Center_dstj = (int)output.cols / 2;
	const double cosA = cos(((angle + 90) * CV_PI / 180));
	const double sinA = sin(((angle + 90) * CV_PI / 180));
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int rotated_i = (int)((j - Center_j) * cosA + (img.rows - 1 - i - Center_i) * -sinA);
			int rotated_j = (int)((j - Center_j) * sinA + (img.rows - 1 - i - Center_i) * cosA);
			rotated_j = (rotated_j + Center_dstj);
			rotated_i = (rotated_i + Center_dsti);
			if (rotated_j < 0 || rotated_j >= output.rows || rotated_i < 0 || rotated_i >= output.cols) continue;
			else {
				output.at<cv::Vec3b>(rotated_i, rotated_j)[0] = img.at<cv::Vec3b>(i, j)[0];
				output.at<cv::Vec3b>(rotated_i, rotated_j)[1] = img.at<cv::Vec3b>(i, j)[1];
				output.at<cv::Vec3b>(rotated_i, rotated_j)[2] = img.at<cv::Vec3b>(i, j)[2];
	
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////
	//                          END OF YOUR CODE                                //
	//////////////////////////////////////////////////////////////////////////////
	cv::imshow("a_output", output); cv::waitKey(0);
	return output;
}

cv::Mat problem_b_rotate_backward(cv::Mat img, double angle){
	cv::Mat output;

	//////////////////////////////////////////////////////////////////////////////
	//                         START OF YOUR CODE                               //
	//////////////////////////////////////////////////////////////////////////////

	int width = img.size().width; //가로
	int height = img.size().height; //세로
	const double cosB = cos(((angle) * CV_PI / 180));
	const double sinB = sin(((angle) * CV_PI / 180));
	int w = abs(width * cosB + height * sinB);
	int h = abs(width * sinB + height * cosB);
	output.create(w, h, img.type());
	output.setTo(0);

	int Center_i, Center_j;
	int Center_dsti, Center_dstj;

	Center_i = static_cast <int> (img.rows / 2);
	Center_j = static_cast <int> (img.cols / 2);
	Center_dsti = static_cast <int> (output.rows / 2);
	Center_dstj = static_cast <int> (output.cols / 2);

	const double cosA = cos(((angle) * CV_PI / 180));
	const double sinA = sin(((angle) * CV_PI / 180));

	for (int i = 0; i < output.rows; i++)
	{
		for (int j = 0; j < output.cols; j++)
		{
			int rotated_i = static_cast <int> ((j - Center_dstj) * cosA + ((output.rows - 1 - i) - Center_dsti) * -sinA);

			int rotated_j = static_cast <int> ((j - Center_dstj) * sinA + ((output.rows - 1 - i) - Center_dsti) * cosA);

			rotated_i = (rotated_i + Center_i);
			rotated_j = (rotated_j + Center_j);

			if (rotated_j < 0 || rotated_j >= img.cols || rotated_i < 0 || rotated_i >= img.rows)
				continue;
			else {
					output.at<cv::Vec3b>(i, j)[0] = img.at<cv::Vec3b>(rotated_i, rotated_j)[0];
					output.at<cv::Vec3b>(i, j)[1] = img.at<cv::Vec3b>(rotated_i, rotated_j)[1];
					output.at<cv::Vec3b>(i, j)[2] = img.at<cv::Vec3b>(rotated_i, rotated_j)[2];
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////
	//                          END OF YOUR CODE                                //
	//////////////////////////////////////////////////////////////////////////////

	cv::imshow("b_output", output); cv::waitKey(0);

	return output;
}

cv::Mat problem_c_rotate_backward_interarea(cv::Mat img, double angle){
	cv::Mat output;
	cv::Mat m1;
	cv::Mat m2;
	//////////////////////////////////////////////////////////////////////////////
	//                         START OF YOUR CODE                               //
	//////////////////////////////////////////////////////////////////////////////
	int width = img.size().width; //가로
	int height = img.size().height; //세로
	const double cosB = cos(((angle) * CV_PI / 180));
	const double sinB = sin(((angle) * CV_PI / 180));
	int _w = abs(width * cosB + height * sinB);
	int _h = abs(width * sinB + height * cosB);
	output.create(_w, _h, img.type());
	output.setTo(0);
	m1.create(_w, _h, img.type());
	m1.setTo(0);
	m2.create(_h, _h, img.type());
	m2.setTo(0);

	int Center_i, Center_j;
	int Center_dsti, Center_dstj;

	Center_i = static_cast <int> (img.rows / 2);
	Center_j = static_cast <int> (img.cols / 2);
	Center_dsti = static_cast <int> (output.rows / 2);
	Center_dstj = static_cast <int> (output.cols / 2);

	const double cosA = cos(((angle) * CV_PI / 180));
	const double sinA = sin(((angle) * CV_PI / 180));
	for (int i = 0; i < output.rows; i++){
		for (int j = 0; j < output.cols; j++){
			int rotated_i = static_cast <int> ((j - Center_dstj) * cosA + ((output.rows - 1 - i) - Center_dsti) * -sinA);
			int rotated_j = static_cast <int> ((j - Center_dstj) * sinA + ((output.rows - 1 - i) - Center_dsti) * cosA);

			rotated_i = (rotated_i + Center_i);
			rotated_j = (rotated_j + Center_j);

			if (rotated_j < 0 || rotated_j >= img.cols || rotated_i < 0 || rotated_i >= img.rows)
				continue;
			else {
				m1.at<cv::Vec3b>(i, j)[0] = img.at<cv::Vec3b>(rotated_i, rotated_j)[0];
				m1.at<cv::Vec3b>(i, j)[1] = img.at<cv::Vec3b>(rotated_i, rotated_j)[1];
				m1.at<cv::Vec3b>(i, j)[2] = img.at<cv::Vec3b>(rotated_i, rotated_j)[2];
			}
		}
	}
	int rate = 1;
	for (int y = 0; y < output.rows; y++) {
		for (int x = 0; x < output.cols; x++) {
			int px = (int)(x / rate);
			int py = (int)(y / rate);

			double fx1 = (double)x / (double)rate - (double)px;
			double fx2 = 1 - fx1;
			double fy1 = (double)y / (double)rate - (double)(py);
			double fy2 = 1 - fy1;

			double w1 = fx2 * fy2;
			double w2 = fx1 * fy2;
			double w3 = fx2 * fy1;
			double w4 = fx1 * fy1;
		}
	}
	cv::Point2f center((img.cols - 1) / 2.0, (img.rows - 1) / 2.0);
	cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
	cv::Rect bbox = cv::RotatedRect(cv::Point2f(), img.size(), angle).boundingRect();
	rot.at<double>(0, 2) += bbox.width / 2.0 - img.cols / 2.0;
	rot.at<double>(1, 2) += bbox.height / 2.0 - img.rows / 2.0;
	cv::resize(img, m1, img.size(), INTER_AREA);
	cv::warpAffine(m1, output, rot, bbox.size());
	//////////////////////////////////////////////////////////////////////////////
	//                          END OF YOUR CODE                                //
	//////////////////////////////////////////////////////////////////////////////

	cv::imshow("c_output", output); cv::waitKey(0);

	return output;
}

cv::Mat Example_change_brightness(cv::Mat img, int num, int x, int y) {
	/*
	img : input image
	num : number for brightness (increase or decrease)
	x : x coordinate of image (for square part)
	y : y coordinate of image (for square part)

	*/
	cv::Mat output = img.clone();
	int size = 100;
	int height = (y + 100 > img.cols) ? img.cols : y + 100;
	int width = (x + 100 > img.rows) ? img.rows : x + 100;

	for (int i = x; i < width; i++)
	{
		for (int j = y; j < height; j++)
		{
			for (int c = 0; c < img.channels(); c++)
			{
				int t = img.at<cv::Vec3b>(i, j)[c] + num;
				output.at<cv::Vec3b>(i, j)[c] = t > 255 ? 255 : t < 0 ? 0 : t;
			}
		}

	}
	cv::imshow("output1", img);
	cv::imshow("output2", output);
	cv::waitKey(0);
	return output;
}

int main(void){

	double angle = 45.0f;

	cv::Mat input = cv::imread("lena.jpg");
	//Fill problem_a_rotate_forward and show output
	problem_a_rotate_forward(input, angle);
	//Fill problem_b_rotate_backward and show output
	problem_b_rotate_backward(input, angle);
	//Fill problem_c_rotate_backward_interarea and show output
	problem_c_rotate_backward_interarea(input, angle);
	//Example how to access pixel value, change params if you want
	//Example_change_brightness(input, 100, 50, 125);
}