#include "Header\Surface.h"

Surface::Surface(const colorDbl& surfaceColor, const int& reflModel)
{
	reflectionModel = reflModel;
	color = surfaceColor;

}

const colorDbl& Surface::GetColor() const
{
	// TODO: insert return statement here
	return color;
}
