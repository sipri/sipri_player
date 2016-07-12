#include "stdafx.h"
#include "Main.h"
#include <locale>

using namespace sipri_mp3_player;
using namespace std;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	locale::global(std::locale(""));

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	Application::Run(gcnew MainForm());
	return 0;
}
