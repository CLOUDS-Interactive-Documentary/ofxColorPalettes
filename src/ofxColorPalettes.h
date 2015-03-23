/********************************************************************************** 
 
 Copyright (C) 2012 Syed Reza Ali (www.syedrezaali.com)
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 of the Software, and to permit persons to whom the Software is furnished to do
 so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 
 **********************************************************************************/

#ifndef OFX_COLORPALETTES
#define OFX_COLORPALETTES

#include "ofxColorPalette.h"

class ofxColorPalettes
{
public:
	
	ofxColorPalettes()
	{
		loadDefaultPalletes(); 
	}	
	
	ofxColorPalettes(string directoryURL)
	{
		loadFromDirectory(directoryURL); 
	}
	
	void loadFromDirectory(string directoryURL)
	{
		ofDirectory dir;
		dir.allowExt("jpg");
		dir.allowExt("png");
		dir.allowExt("gif");
		dir.allowExt("tiff");
		
		dir.listDir(directoryURL);
		//dir.sort();
		
		for(int i = 0; i < (int)dir.size(); i++)
		{
			palletes.push_back(ofxColorPalette(dir.getPath(i)));
		}		
	}
	
	ofxColorPalette& getPallete(int index)
	{
		return palletes[index%palletes.size()]; 
	}
	
    ofxColorPalette *getPalletePointer(int index)
    {
		return &(palletes[index%palletes.size()]);
    }
    
	int getCount()
	{
		return palletes.size(); 
	}
	
	void clear()
	{
		for(int i = 0; i < palletes.size(); i++)
		{
			palletes[i].clear(); 
		}
	}
	
	void loadDefaultPalletes()
	{

	}							
	
	vector<ofxColorPalette> palletes; 		

}; 


#endif
