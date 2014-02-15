/*
 * PluginColorToGray.cpp
 *
 *  Created on: 13/02/2014
 *      Author: willytell
 */

#include "PluginColorToGray.h"

PluginColorToGray::PluginColorToGray() {
	// TODO Auto-generated constructor stub

}

PluginColorToGray::~PluginColorToGray() {
	// TODO Auto-generated destructor stub
}


bool PluginColorToGray::process(FrameData *data) {
	Mat *gray;
	if ((gray=(cv::Mat *)data->map.get("gray_img")) == 0) {
	    gray=(cv::Mat *)data->map.insert( "gray_img", new Mat );
	}

	if ((data->frame.channels() == 3 || data->frame.channels() == 4))
		cvtColor(data->frame, *gray, CV_BGR2GRAY);

	return true;
}

std::string PluginColorToGray::getName() {
	return "ColorToGray";
}
