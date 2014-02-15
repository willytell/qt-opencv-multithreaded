/*
 * MyProcessing.cpp
 *
 *  Created on: 13/02/2014
 *      Author: willytell
 */

#include "MyProcessing.h"

MyProcessing::MyProcessing(SharedImageBuffer *sharedImageBuffer, int deviceNumber) {
	// Save Device Number
	this->deviceNumber=deviceNumber;
	// Initialize members
	doStop=false;
	sampleNumber=0;
	fpsSum=0;
	fps.clear();
	statsData.averageFPS=0;
	statsData.nFramesProcessed=0;
	rb = sharedImageBuffer->getByDeviceNumber(deviceNumber);

	// Create the Plugin Stack
	pluginStack = new PluginStack();

	// Here add your plugin to the stack
	pluginStack->stack.push_back(new PluginColorToGray());
	pluginStack->stack.push_back(new PluginFlip());
	pluginStack->stack.push_back(new PluginBlur());
	// pluginStack->stack.push_back(new Plugin2());
	// pluginStack->stack.push_back(new Plugin3());
	// ...
	// pluginStack->stack.push_back(new PluginN());
	// ---------------------------------
}

MyProcessing::~MyProcessing() {
	// TODO Auto-generated destructor stub
}

void MyProcessing::process() {

}

int MyProcessing::getAvgFPS() {
	return 0;
}

void MyProcessing::run () {
	long long prevFrameNum, curFrameNum;
	prevFrameNum = -1;
	curFrameNum = 0;

    while(1)
    {
        ////////////////////////////////
        // Stop thread if doStop=TRUE //
        ////////////////////////////////
        doStopMutex.lock();
        if(doStop)
        {
            doStop=false;
            doStopMutex.unlock();
            break;
        }
        doStopMutex.unlock();
        /////////////////////////////////
        /////////////////////////////////

        int idx = rb->curRead();
        FrameData *d = rb->getPointer(idx);
        curFrameNum = d->frameNumber;
        if (prevFrameNum < curFrameNum) {
        	// Save processing time
        	processingTime=t.elapsed();
        	// Start timer (used to calculate processing rate)
        	t.start();

        	processingMutex.lock();
        	//rb->lockRead();
        	pluginStack->process(d);

        	Mat currentFrame = d->frame.clone();
        	//cout << "frame number : " << d->frameNumber << endl;

        	//rb->unlockRead();
            // Convert Mat to QImage
            frame=MatToQImage(currentFrame);
            processingMutex.unlock();

            // Inform GUI thread of new frame (QImage)
            emit newFrame(frame);

            // Update statistics
            updateFPS(processingTime);
            statsData.nFramesProcessed++;
            // Inform GUI of updated statistics
            emit updateStatisticsInGUI(statsData);
        }//if

        // With "true" it jumps directly ahead to the most recent data available. This means that we can possibly skip bins.
        rb->nextRead(true);
        prevFrameNum=curFrameNum;
    }
    //qDebug() << "Stopping processing thread...";

}

void MyProcessing::updateFPS(int timeElapsed)
{
    // Add instantaneous FPS value to queue
    if(timeElapsed>0)
    {
        fps.enqueue((int)1000/timeElapsed);
        // Increment sample number
        sampleNumber++;
    }

    // Maximum size of queue is DEFAULT_PROCESSING_FPS_STAT_QUEUE_LENGTH
    if(fps.size()>PROCESSING_FPS_STAT_QUEUE_LENGTH)
        fps.dequeue();

    // Update FPS value every DEFAULT_PROCESSING_FPS_STAT_QUEUE_LENGTH samples
    if((fps.size()==PROCESSING_FPS_STAT_QUEUE_LENGTH)&&(sampleNumber==PROCESSING_FPS_STAT_QUEUE_LENGTH))
    {
        // Empty queue and store sum
        while(!fps.empty())
            fpsSum+=fps.dequeue();
        // Calculate average FPS
        statsData.averageFPS=fpsSum/PROCESSING_FPS_STAT_QUEUE_LENGTH;
        // Reset sum
        fpsSum=0;
        // Reset sample number
        sampleNumber=0;
    }
}

void MyProcessing::stop()
{
    QMutexLocker locker(&doStopMutex);
    doStop=true;
}
