/*
 * MyProcessing.h
 *
 *  Created on: 13/02/2014
 *      Author: willytell
 */

#ifndef MYPROCESSING_H_
#define MYPROCESSING_H_

// Qt
#include <QtCore/QTime>
#include <QtCore/QQueue>
// OpenCV
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
// Local
#include "Structures.h"
#include "Config.h"
#include "MatToQImage.h"
#include "SharedImageBuffer.h"
#include "FrameData.h"
#include "ProcessingThread.h"
// Local plugins
#include "PluginColorToGray.h"
#include "PluginFlip.h"
#include "PluginBlur.h"

//using namespace cv;

class MyProcessing: public ProcessingThread {
	Q_OBJECT
public:
	MyProcessing(SharedImageBuffer *sharedImageBuffer, int deviceNumber);
	virtual ~MyProcessing();

	void process();
	void stop();
	int getAvgFPS();

signals:
	void newFrame(const QImage &frame);
	void updateStatisticsInGUI(struct ThreadStatisticsData);

protected:
    void run();

private:
    void updateFPS(int);
    Mat currentFrame;
	Mat currentFrameGrayscale;
	QImage frame;
	QTime t;
	QQueue<int> fps;
	QMutex processingMutex;
	Size frameSize;
	Point framePoint;
	struct ThreadStatisticsData statsData;
	int processingTime;
	int fpsSum;
	int sampleNumber;
	int deviceNumber;

};

#endif /* MYPROCESSING_H_ */
