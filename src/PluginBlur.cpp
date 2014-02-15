/*
 * PluginBlur.cpp
 *
 *  Created on: 14/02/2014
 *      Author: willytell
 */

#include "PluginBlur.h"
#include <iostream>

PluginBlur::PluginBlur() {
	// TODO Auto-generated constructor stub

}

PluginBlur::~PluginBlur() {
	// TODO Auto-generated destructor stub
}

bool PluginBlur::process(FrameData *data) {
	cv::Mat *flip;
	if ((flip=(cv::Mat *)data->map.get("flip_img")) == 0) {
		cout << "Flipped image lost " << endl;
		return false;
	}

	cv::Mat *blur;
	if ((blur=(cv::Mat *)data->map.get("blur_img")) == 0) {
		blur=(cv::Mat *)data->map.insert( "blur_img", new cv::Mat );
	}

	cv::blur(*flip, *blur, cv::Size(3,3));
	data->frame = blur->clone();
	return true;
}

std::string PluginBlur::getName() {
	return "Blur";
}
