#include "OperatorConsole.h"
#include "Command.h"

//---------------------------------------------------------

void OperatorConsole::issue(Command* cmd) {
	
    if (!cmd) {
            std::cout << "[OperatorConsole] Null command issued.\n";
            return;
        }

        cmd->execute();
        history.push_back(cmd);
}

//---------------------------------------------------------

void OperatorConsole::undoLast() {
	
    if (history.empty()) {
            std::cout << "[OperatorConsole] History is empty. Nothing to undo.\n";
            return;
        }

        Command* lastCmd = history.back();
        history.pop_back();

        if (lastCmd) {
            lastCmd->undo();
            delete lastCmd; // Free the allocated command object
        }
}

//---------------------------------------------------------
