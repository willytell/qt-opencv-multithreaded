/*
 * PluginFlip.cpp
 *
 *  Created on: 13/02/2014
 *      Author: willytell
 */

#include "PluginFlip.h"
#include <iostream>

PluginFlip::PluginFlip() {
	// TODO Auto-generated constructor stub

}

PluginFlip::~PluginFlip() {
	// TODO Auto-generated destructor stub
}

bool PluginFlip::process(FrameData *data) {
	cv::Mat *gray;
	if ((gray=(cv::Mat *)data->map.get("gray_img")) == 0) {
		cout << "Gray image lost " << endl;
		return false;
	}

	cv::Mat *flip;
		if ((flip=(cv::Mat *)data->map.get("flip_img")) == 0) {
			flip=(cv::Mat *)data->map.insert( "flip_img", new cv::Mat );
	}

	cv::flip(*gray, *flip, 0);
	return true;
}

std::string PluginFlip::getName() {
	return "Flip";
}
