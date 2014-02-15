#ifndef PROCESSINGTHREAD_H
#define PROCESSINGTHREAD_H

// Qt
#include <QtCore/QThread>
// Local
#include "FrameData.h"
#include "SharedImageBuffer.h"
#include "PluginStack.h"


class ProcessingThread : public QThread {
	Q_OBJECT
protected:
        PluginStack *pluginStack;
        QMutex doStopMutex;
        volatile bool doStop;
        FrameBuffer * rb;

public:
        ProcessingThread (); //SharedImageBuffer *sharedImageBuffer, int deviceNumber);
        virtual void process()=0;
        virtual void stop()=0;
        //virtual void updateFPS(int timeElapsed)=0;

protected:
        virtual void run()=0;

};

#endif // PROCESSINGTHREAD_H
