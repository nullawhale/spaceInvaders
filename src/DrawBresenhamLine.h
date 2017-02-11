#ifndef __DRAW_BRES_LINE__
#define __DRAW_BRES_LINE__

class DrawBresenhamLine{
public:
	DrawBresenhamLine();
	double sign(double x);
	void drawPoint(double x, double y);
	void drawLine(double x, double y, double x1, double y1);
};

#endif // __DRAW_BRES_LINE__