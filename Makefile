# how to use
# install make, bisa pake choco 'choco install make' (run as admin ya). kalo gk salah kita juga make choco waktu haskell, jdi hrusnya di device kalian udah ada.
# ngerunnya gini, "make hello", buat ngerun hello:	
hello: 
	@echo hello world

compile:
	@gcc main.c ADT\bag.c ADT\building.c ADT\buildingList.c ADT\gadgetInventory.c ADT\inProgressList.c ADT\location.c ADT\nearBuilding.c ADT\nodePaket.c ADT\orderList.c ADT\paket.c ADT\todoList.c command\command_BUY.c command\command_DROP_OFF.c command\command_HELP.c command\command_IN_PROGRESS.c command\command_MAP.c command\command_MOVE.c command\command_PICK_UP.c command\command_TO_DO.c command\command_INVENTORY.c fungsi\commandInput.c fungsi\gameStateInput.c fungsi\intInput.c fungsi\isContinue.c fungsi\machine.c fungsi/lettermachine.c pcolor\pcolor.c debug.c fungsi\getLoc.c 
compile2:
	@gcc main.c ADT/bag.c ADT/building.c ADT/buildingList.c ADT/gadgetInventory.c ADT/inProgressList.c ADT/location.c ADT/nearBuilding.c ADT/nodePaket.c ADT/orderList.c ADT/paket.c ADT/todoList.c command/command_BUY.c command/command_DROP_OFF.c command/command_HELP.c command/command_IN_PROGRESS.c command/command_MAP.c command/command_MOVE.c command/command_PICK_UP.c command/command_TO_DO.c command/command_INVENTORY.c fungsi/commandInput.c fungsi/gameStateInput.c fungsi/intInput.c fungsi/isContinue.c fungsi/machine.c fungsi/lettermachine.c pcolor/pcolor.c debug.c fungsi/getLoc.c 