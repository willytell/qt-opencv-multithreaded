/*
 * PluginStack.h
 *
 *  Created on: 03/12/2013
 *      Author: willytell
 */

#ifndef PLUGINSTACK_H_
#define PLUGINSTACK_H_

// C++
#include <vector>
#include <stdio.h>
// Local
#include "PluginVision.h"
#include "FrameData.h"
#include "timer.h"

using namespace std;

class PluginStack {
protected:
	double total;

public:
	PluginStack();
	virtual ~PluginStack();

	vector<PluginVision *> stack;

	void process(FrameData * data);
	double getTotalProcessTime();

};

#endif /* PLUGINSTACK_H_ */
