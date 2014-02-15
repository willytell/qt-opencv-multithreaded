/*
 * PluginVision.cpp
 *
 *  Created on: 03/12/2013
 *      Author: willytell
 */

#include "PluginVision.h"

PluginVision::PluginVision() {
	// TODO Auto-generated constructor stub

}

PluginVision::~PluginVision() {
	// TODO Auto-generated destructor stub
}

std::string PluginVision::getName() {
	return "Unnamed";
}

void PluginVision::lock() {
  mutex.lock();
}

void PluginVision::unlock() {
  mutex.unlock();
}

void PluginVision::setTimeProcessing(double val) {
	processingTime=val;
}

double PluginVision::getTimeProcessing() {
  return processingTime;
}
