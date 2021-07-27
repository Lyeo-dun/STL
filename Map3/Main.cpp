#include "MainUpdate.h"

int main(void)
{
	MainUpdate Main;

	Main.Initialize();

	Main.Update();
	Main.Render();

	Main.Release();

	return 0;
}