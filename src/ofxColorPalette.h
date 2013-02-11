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

#ifndef OFX_COLORPALETTE
#define OFX_COLORPALETTE

#include "ofMain.h"
#include <map>

class ofxColorPalette
{
public:
	ofxColorPalette(string imgURL)
	{
		ofImage img; 
		img.loadImage(imgURL); 
		
		ofColor clr; 
		for(int x = 0; x < img.width; x++)
		{
			clr = img.getColor(x,0); 
			colorMap.insert( pair<int,ofColor>(clr.getHex(),clr) ); 
		}
		
		map<int,ofColor>::iterator it;
		
		for ( it=colorMap.begin() ; it != colorMap.end(); it++ )
		{
			ofColor clr = (*it).second; 
			colors.push_back(clr); 
		}
		
		for(int i = 0; i < colors.size(); i++)
		{
			ofColor clr = colors[i]; 
		}
	}
	
	ofxColorPalette(vector<ofColor> colorsVector)
	{
		for(int i = 0; i < colorsVector.size(); i++)			
		{			
			colorMap.insert( pair<int,ofColor>(colorsVector[i].getHex(),colorsVector[i]) ); 
		}
		
		colors = colorsVector; 
	}
	
	void loadFromImage(ofImage img)
	{
		colorMap.clear(); 
		colors.clear(); 
	
	}
	
	void draw()
	{
		
	}
	
	void clear()
	{
		colorMap.clear(); 
		colors.clear(); 	
	}
	
    int getCount()
    {
        return colors.size();
    }
    
	~ofxColorPalette()
	{
		colorMap.clear(); 
		colors.clear(); 		
	}
	
	ofColor &getColor(int index)
	{		
		return colors[index%colors.size()]; 
	}
	
	void toConsole()
	{
		cout << "{" << endl;   
		cout << "vector<ofColor> colors; " << endl; 
		for(int i = 0; i < colors.size(); i++)
		{
			cout << "colors.push_back(ofColor(" << (int)colors[i].r << "," << (int)colors[i].g << "," << (int)colors[i].b << "));" << endl; 
		}
		cout << "palletes.push_back(ofxColorPalette(colors));" << endl; 
		cout << "}" << endl; 
	}
    
    vector<ofColor> &getPaletteVector()
    {
        return colors; 
    }
    
	//properties 
	map<int, ofColor> colorMap; 	
	vector<ofColor> colors; 
}; 


#endif
