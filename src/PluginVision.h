/*
 * PluginVision.h
 *
 *  Created on: 03/12/2013
 *      Author: willytell
 */

#ifndef PLUGINVISION_H_
#define PLUGINVISION_H_

// Qt
#include <QMutex>
// C++
#include <string>
// Local
#include "FrameData.h"

class PluginVision {
protected:
    QMutex mutex;
    double processingTime;

public:
	PluginVision();
	virtual ~PluginVision();

	virtual bool process(FrameData *data) = 0;
	virtual std::string getName();	//Overload it to return the name of your plugin

    void lock();
    void unlock();

    void setTimeProcessing(double val);
    double getTimeProcessing();
};

#endif /* PLUGINVISION_H_ */
