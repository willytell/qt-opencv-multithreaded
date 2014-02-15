/*
 * PluginStack.cpp
 *
 *  Created on: 03/12/2013
 *      Author: willytell
 */

#include "PluginStack.h"

PluginStack::PluginStack() {
	// TODO Auto-generated constructor stub

}

PluginStack::~PluginStack() {
	// TODO Auto-generated destructor stub
}

double PluginStack::getTotalProcessTime(){
	return total;
}

void PluginStack::process(FrameData * data) {
	double a=0.0;
	double b=0.0;
	unsigned int n=stack.size();
	PluginVision * p;
	total=0.0;
	bool show_timing = true;
	if (show_timing) printf("----------\n");
	for (unsigned int i=0;i<n;i++) {
		p=stack[i];
		p->lock();
	    a=GetTimeSec();
	    p->process(data);
	    b=GetTimeSec();
	    p->setTimeProcessing(b-a);
	    total+=(p->getTimeProcessing());
	    if (show_timing) {
	    	printf("Plugin %s: %fms\n",p->getName().c_str(),  p->getTimeProcessing() * 1000.0);
	    }
	    p->unlock();
	}
	if (show_timing) printf("Total time: %fms\n",total * 1000.0);
}
