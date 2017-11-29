#ifndef GROUND_H_IS_INCLUDED
#define GROUND_H_IS_INCLUDED


class CharBitmap
{
protected:
	int wid, hei;
	char *dat;
	int gap[7] = { 69,70,86,87,88,153,154 };
	int cloud_x[20], cloud_y[20];
	
	double xx1, yy1, vx1, vy1;
	double xx2, yy2, vx2, vy2;
	double xx3, yy3, vx3, vy3;
	double xx4, yy4, vx4, vy4;
	double xx5, yy5, vx5, vy5;
	double mmx, mmy, vmx, vmy;
	double dt;

public:
	CharBitmap();
	~CharBitmap();
	void CleanUp(void);

	CharBitmap(const CharBitmap &incoming);
	CharBitmap &operator=(const CharBitmap &incoming);

	int state, flag1, flag2, flag3;
	double mx, my;
	int GetWidth(void) const;
	int GetHeight(void) const;
	void SetBitmap(int bmpWid, int bmpHei, char bmp[]);
	void SetPixel(int x, int y, char c) const;
	char GetPixel(int x, int y) const;

	// Move function
	void Move1(void);
	void Move2(void);
	void Move3(void);
	void Move4(void);
	void Move5(void);
	void Move_mario(void);
	void Bounce_mario(void);
	void Jump_mario(void);

	// Draw functions
	inline void Draw_quad(int a, int b);
	inline void Draw_quad1(double a, double b);
	void Draw_bgd(void);
	void Draw_ground(int bias1, int bias2);
	void Draw_cloud(int bias1, int bias2);
	void Draw_grass(int bias1, int bias2);
	void Draw_mountain(int bias1, int bias2);
	void Draw_people1(int bias1, int bias2);
	void Draw_people2(int bias1, int bias2);
	void Draw_people3(int bias1, int bias2);
	void Draw_people4(int bias1, int bias2);
	void Draw_people5(int bias1, int bias2);
	void Draw_Mario(int bias1, int bias2);
	void Mario_jump(int bias1, int bias2);
	void init(void);
	void Draw_everything(int camera_x);
	void Draw_transit(int camera_x, int player_x);
	void Draw_move(int camera_x, int player_x);
};



class Texture
{
protected:
	GLuint texId[14];
	YsRawPngDecoder png[14];
	
public:
	double temp = 0;
	void set_texture(GLuint &texId, YsRawPngDecoder png);
	inline void draw_sth(int x, int y, GLuint texId, int wid, int hei);
	void init(void);
	void set(void);
	void Draw_texture(int camera_x);
	void Draw_soji(int camera_x);
};

void Draw_edding(int player_x, int &camera_x, 
	CharBitmap &bmp, Texture &TX);
void Camera_move(int &camera_x, int &player_x);

#endif
