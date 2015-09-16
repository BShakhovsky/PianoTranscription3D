# include "stdafx.h"
# include "..\..\Model\MidiTracksCompiler.h"
# include "..\..\CodeMetrics\CodeMetrics.h"

using namespace std;
using Model::MidiParser::MidiTracksCompiler;

# ifdef CODE_METRICS
#	define SOLUTION_LINES																						{\
		cout<< "Solution total number of non-blank lines of code: "	<< CODE_METRICS.SolutionLines("../..", true)\
				<< "\n\tUnit tests: "								<< CODE_METRICS.SolutionLines("../gTests")	\
				<< "\n\tModel: "									<< CODE_METRICS.SolutionLines("../../Model")\
			<< '\n' << endl;																					}
# else
#	define SOLUTION_LINES
# endif
int main()
{
# ifdef _DEBUG
	SOLUTION_LINES;
# endif
	try
	{
		MidiTracksCompiler midiFile("../../../../../C++/Projects/Backup Piano-Fingers/Test.mid");
		while (midiFile.LoadNextTrack())
			if (_kbhit())
			{
				auto ignored(_getch());
				++ignored;
				midiFile.UnPause();
			}
		system("Pause");
		midiFile.ShowKeyboard();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		system("Pause");
		throw;
	}

	return NULL;
}