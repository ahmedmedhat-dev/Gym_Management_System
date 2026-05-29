#include "gymSystemManager.h"
int main() {
	SetConsoleOutputCP(CP_UTF8);
	gymSystemManager project;
	project.loadData();
	project.startSystem();
	project.saveData();
	cout << FG_YELLOW << BG_MAGENTA << u8"\t╔═════════════════════════════════════════════════════════════════════════════════════════════════════════╗" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t║                                      Special thanks to our TA:                                          ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t║                                                                                                         ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t║ ███████╗███╗   ██╗ ██████╗██╗   ██╗     █████╗ ██████╗ ██████╗  █████╗ ██╗     ██╗      █████╗ ██╗  ██╗ ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t║ ██╔════╝████╗  ██║██╔════╝╚██╗ ██╔╝    ██╔══██╗██╔══██╗██╔══██╗██╔══██╗██║     ██║     ██╔══██╗██║  ██║ ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t║ █████╗  ██╔██╗ ██║██║  ███╗╚████╔╝     ███████║██████╔╝██║  ██║███████║██║     ██║     ███████║███████║ ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t║ ██╔══╝  ██║╚██╗██║██║   ██║ ╚██╔╝      ██╔══██║██╔══██╗██║  ██║██╔══██║██║     ██║     ██╔══██║██╔══██║ ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t║ ███████╗██║ ╚████║╚██████╔╝  ██║       ██║  ██║██████╔╝██████╔╝██║  ██║███████╗███████╗██║  ██║██║  ██║ ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t║ ╚══════╝╚═╝  ╚═══╝ ╚═════╝   ╚═╝       ╚═╝  ╚═╝╚═════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t║                                                                                                         ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t║                                    Thank you for your support!                                          ║" << RESET << endl;
	cout << FG_YELLOW << BG_MAGENTA << u8"\t╚═════════════════════════════════════════════════════════════════════════════════════════════════════════╝" << RESET << endl;

	//cout << "\033[38;2;255;178;178mThis text is light pink (#ffb2b2)\033[0m" << endl;
	cout << u8"\t\t\t\t\t\t     ♥♥♥♥♥♥     ♥♥♥♥♥♥    \n";
	cout << u8"\t\t\t\t\t\t    ♥♥♥♥♥♥♥♥♥♥ ♥♥♥♥♥♥♥♥♥♥	 \n";
	cout << u8"\t\t\t\t\t\t   ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥	 \n";
	cout << u8"\t\t\t\t\t\t  ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥ \n";
	cout << u8"\t\t\t\t\t\t ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥\n";
	cout << u8"\t\t\t\t\t\t ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥\n";
	cout << u8"\t\t\t\t\t\t ♥♥♥♥♥ Hope to see you ♥♥♥♥♥\n";
	cout << u8"\t\t\t\t\t\t ♥♥♥♥♥♥♥ again :) ♥♥♥♥♥♥♥♥♥ \n";
	cout << u8"\t\t\t\t\t\t  ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥	 \n";
	cout << u8"\t\t\t\t\t\t   ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥		 \n";
	cout << u8"\t\t\t\t\t\t    ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥			 \n";
	cout << u8"\t\t\t\t\t\t     ♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥			 \n";
	cout << u8"\t\t\t\t\t\t       ♥♥♥♥♥♥♥♥♥♥♥♥				 \n";
	cout << u8"\t\t\t\t\t\t         ♥♥♥♥♥♥♥♥					 \n";
	cout << u8"\t\t\t\t\t\t           ♥♥♥♥						 \n";
	cout << u8"\t\t\t\t\t\t            ♥♥							 \n";
	return 0;
}