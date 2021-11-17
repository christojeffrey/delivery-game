# how to use
# install make, bisa pake choco 'choco install make' (run as admin ya). kalo gk salah kita juga make choco waktu haskell, jdi hrusnya di device kalian udah ada.
# ngerunnya gini, "make hello", buat ngerun hello:	
hello: 
	@echo hello world

compile:
	@gcc main.c ADT\bag\bag.c ADT\building\building.c ADT\buildingList\buildingList.c ADT\gadgetInventory\gadgetInventory.c ADT\inProgressList\inProgressList.c ADT\location\location.c ADT\nearBuilding\nearBuilding.c ADT\nodePaket\nodePaket.c ADT\orderList\orderList.c ADT\paket\paket.c ADT\todoList\todoList.c ADT\machine\machine.c ADT\lettermachine\lettermachine.c command\command_BUY.c command\command_DROP_OFF.c command\command_HELP.c command\command_IN_PROGRESS.c command\command_MAP.c command\command_MOVE.c command\command_PICK_UP.c command\command_TO_DO.c command\command_INVENTORY.c fungsi\commandInput.c fungsi\gameStateInput.c fungsi\intInput.c fungsi\isContinue.c  pcolor\pcolor.c fungsi\getLoc.c fungsi\getType.c debug.c
compile2:
	@gcc main.c ADT/bag/bag.c ADT/building/building.c ADT/buildingList/buildingList.c ADT/gadgetInventory/gadgetInventory.c ADT/inProgressList/inProgressList.c ADT/location/location.c ADT/nearBuilding/nearBuilding.c ADT/nodePaket/nodePaket.c ADT/orderList/orderList.c ADT/paket/paket.c ADT/todoList/todoList.c ADT/machine/machine.c ADT/lettermachine/lettermachine.c command/command_BUY.c command/command_DROP_OFF.c command/command_HELP.c command/command_IN_PROGRESS.c command/command_MAP.c command/command_MOVE.c command/command_PICK_UP.c command/command_TO_DO.c command/command_INVENTORY.c fungsi/commandInput.c fungsi/gameStateInput.c fungsi/intInput.c fungsi/isContinue.c  pcolor/pcolor.c fungsi/getLoc.c fungsi/getType.c debug.c -lm