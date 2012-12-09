
#include "CApp.h"

CLabel::CLabel(int X, int Y, std::string text, int R, int G, int B) : text(text)
{
	//On edite le SDL_Rect de l'objet
	position.x = X;
	position.y = Y;

	//On cr�e la couleure
	SDL_Color tempcol = {R,G,B};
	color = tempcol;

	//On r�cup�re la font
	font = getFont();

	//On fait pointer l'attribut Surf_Label sur la surface cr��e
	Surf_Label = TTF_RenderText_Blended(font, text.c_str(), color );

	//On ajoute ce nouvel objet � la liste
	labels.push_back(*this);

}

CLabel::~CLabel()
{
}
// 
//SDL_Surface* CLabel::createLabel(int X, int Y, std::string text)
//{
//
//}
//
//bool CLabel::destroyLabel()
//{
//}
//
//SDL_Rect CLabel::getPosition()
//{
//}
//
//bool CLabel::setPosition(int X, int Y)
//{
//}
//
//std::string CLabel::getText()
//{
//}
//
//bool CLabel::setText(std::string text)
//{
//}

std::vector<CLabel> CLabel::labels;

bool CLabel::renderLabels()
{
	
	for(int i(0); i<CLabel::labels.size(); ++i)
	{
		SDL_BlitSurface((CLabel::labels)[i].Surf_Label, NULL, getBackground(), &(CLabel::labels)[i].position);
	}

	return true;
}