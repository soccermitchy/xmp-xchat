/*
 * main-hexchat.cpp
 *
 *  Created on: Jul 8, 2013
 *  Author: Mitchell Monahan
 *
 *  VERY loosely based on the example from http://xmp.sourceforge.net/libxmp.html
 *  (only the function syntax and things to do to keep a module running
 */

#define MODPATH "/home/mitchell/chipmusic/1993.mod"
extern "C" {
	#include <xmp.h>
}
#include <iostream>
using namespace std;
int main() {
	xmp_context xmpcontext1;
	int laststatus;
	struct xmp_frame_info modinfo;
	cout << "current xmp version" << XMP_VERSION << endl; // output XMP version
	xmpcontext1=xmp_create_context(); // Create a new context for XMP to use
	laststatus = xmp_load_module(xmpcontext1,MODPATH);
	if (laststatus == 0) {
		cout << "load successful for module at " << MODPATH << ", will play." << endl;
	} else {
		cout << "Could not load module at " << MODPATH << ", exiting.." << endl;
		return 1;
	}
	laststatus = xmp_start_player(xmpcontext1,44100,0);
	if (laststatus != 0) {
			cout << "Unknown error playing module. Exiting..." << endl;
			return 1;
	}
	while (xmp_play_frame(xmpcontext1) == 0) {
		xmp_get_frame_info(xmpcontext1,&modinfo);
		if (modinfo.loop_count > 0)
			break; // exit before we loop
	}
	xmp_end_player(xmpcontext1);
	xmp_release_module(xmpcontext1);
	xmp_free_context(xmpcontext1);
	cout << "done playing" << endl;
	return 0;
}
