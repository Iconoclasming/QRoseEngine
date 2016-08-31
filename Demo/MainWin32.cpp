#include <QRoseEngineCore.h>

using namespace QRose;

void main()
{
	WindowDesc windowDesc("Awesome Sample Game", Size<int>(800, 600));
	GraphicsDesc graphicsDesc(windowDesc, Color(24, 42, 51));
	Engine* pEngine = EngineFactory::CreateEngine(graphicsDesc);
	//engine->Exit += &OnExit;

	Scene mainScene/*(some actors list)*/;
	pEngine->PresentScene(mainScene);
}

/*class MyScene : public Scene
{
public:
//...
};*/