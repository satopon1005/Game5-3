#pragma once

class Collision {
public:

	//当たっているときどの方向から当たっているか
	static int GetHitDirectionX2D(float objects_x, int size_x1, float use_x, int size_x2, float& overlap_x);
	static int GetHitDirectionY2D(float objects_y, int size_y1, float use_y, int size_y2, float& overlap_y);

	//矩形の当たり判定
	static bool IsHitRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);

	//円の当たり判定
	static bool IsHitCircle(float x1, float y1, float r1, float x2, float y2, float r2);

	//円と矩形の当たり判定
	static bool IsHitCircleRect(float x1, float y1, float r1, float x2, float y2, float w2, float h2);

	//矩形と点の当たり判定
	static bool IsHitRectPoint(float rect_x, float rect_y, float rect_w, float rect_h, float point_pos_x, float point_pos_y);

	//円と点の当たり判定
	static bool IsHitCirclePoint(float circcle_pos_x, float circcle_pos_y, float circle_len, float point_pos_x, float point_pos_y);

	//円と線の当たり判定
	static bool IsHitCircleLine(float circle_x, float circle_y, float circle_len,
		float line_start_x, float line_start_y, float line_end_x, float line_end_y);
};