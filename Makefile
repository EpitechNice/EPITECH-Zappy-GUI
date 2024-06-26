##
## EPITECH PROJECT, 2024
## Zappy GUI
## File description:
## Makefile
##


SRC		=   src/Main.cpp																				\
			src/Components/0000/AComponent/AComponent.cpp												\
			src/Components/Background2D/ComponentBackground2D.cpp										\
			src/Components/Button/ComponentButton.cpp													\
			src/Components/ButtonClassic/ComponentButtonClassic.cpp										\
			src/Components/Chatbox/ComponentChatbox.cpp													\
			src/Components/Circle/ComponentCircle.cpp													\
			src/Components/Cube/ComponentCube.cpp														\
			src/Components/Image/ComponentImage.cpp														\
			src/Components/Inspecter/ComponentInspecter.cpp												\
			src/Components/InspecterInfo/ComponentInspecterInfo.cpp										\
			src/Components/InspecterInfoTile/ComponentInspecterInfoTile.cpp								\
			src/Components/InspecterSelecter/ComponentInspecterSelecter.cpp								\
			src/Components/InspecterSelecterGroup/ComponentInspecterSelecterGroup.cpp					\
			src/Components/InspecterSelecterGroupDraggable/ComponentInspecterSelecterGroupDraggable.cpp	\
			src/Components/Model3D/ComponentModel3D.cpp													\
			src/Components/Rectangle/ComponentRectangle.cpp												\
			src/Components/Ressources/ComponentRessources.cpp											\
			src/Components/RoundedRectangle/ComponentRoundedRectangle.cpp								\
			src/Components/Skybox/ComponentSkybox.cpp													\
			src/Components/SliderVolume/ComponentSliderVolume.cpp										\
			src/Components/Text/ComponentText.cpp														\
			src/Components/TextBox/ComponentTextBox.cpp 			 									\
			src/Components/TextGroup/ComponentTextGroup.cpp												\
			src/Components/TextGroupDraggable/ComponentTextGroupDraggable.cpp							\
			src/Components/TextMessage/ComponentTextMessage.cpp											\
			src/Components/Tile/ComponentTile.cpp														\
			src/Components/TileMap/ComponentTileMap.cpp													\
			src/Components/VolumeSection/ComponentVolumeSection.cpp										\
			src/Components/DelayServerSection/ComponentDelayServerSection.cpp							\
			src/Exceptions/Exceptions.cpp																\
			src/I18n/I18nHelper.cpp																		\
			src/Parsing/Parsing.cpp																		\
			src/Parsing/ParsingError.cpp																\
			src/Parsing/ParsingHelp.cpp																	\
			src/Raylib/ColorManager/ColorManager.cpp													\
			src/Raylib/FontManager/FontManager.cpp														\
			src/Raylib/ModelManager/ModelManager.cpp													\
			src/Raylib/Render/Render.cpp																\
			src/Raylib/TextureManager/TextureManager.cpp												\
			src/Raylib/View/View.cpp																	\
			src/Ressources/Eggs/Eggs.cpp																\
			src/Ressources/Players/Players.cpp															\
			src/Ressources/Ref/Ref.cpp																	\
			src/Ressources/Ressources/Ressources.cpp													\
			src/Ressources/TileRessources/TileRessources.cpp											\
			src/SceneManager/SceneManager.cpp															\
			src/Scenes/AScene/AScene.cpp																\
			src/Scenes/CreditScene/CreditScene.cpp														\
			src/Scenes/CreditScene/DisplayCreditScene/DisplayCreditScene.cpp							\
			src/Scenes/GameScene/GameScene.cpp															\
			src/Scenes/HelperScene/HelperScene.cpp														\
			src/Scenes/MenuScene/MenuScene.cpp															\
			src/Scenes/OptionScene/OptionScene.cpp														\
			src/Scenes/OptionScene/ResolutionOption/ResolutionOptionScene.cpp							\
			src/Scenes/OptionScene/SoundOption/SoundOptionScene.cpp										\
			src/Server/Server/Server.cpp																\
			src/Server/Mutex/Mutex.cpp																	\
			src/Server/Thread/Thread.cpp																\
			src/Server/Commands/Commands.cpp															\
			src/Server/SharedMemory/SharedMemory.cpp													\
			src/Sfml/SoundManager/SoundManager.cpp														\
			src/Utils/Path/Path.cpp																		\
			src/Utils/RelativePlayerPosition/RelativePlayerPosition.cpp									\
			src/Utils/Utils/Utils.cpp																	\

TEST_SRC	=	src/Components/0000/AComponent/AComponent.cpp												\
				src/Components/Background2D/ComponentBackground2D.cpp										\
				src/Components/Button/ComponentButton.cpp													\
				src/Components/ButtonClassic/ComponentButtonClassic.cpp										\
				src/Components/Chatbox/ComponentChatbox.cpp													\
				src/Components/Circle/ComponentCircle.cpp													\
				src/Components/Cube/ComponentCube.cpp														\
				src/Components/Image/ComponentImage.cpp														\
				src/Components/Inspecter/ComponentInspecter.cpp												\
				src/Components/InspecterInfo/ComponentInspecterInfo.cpp										\
				src/Components/InspecterInfoTile/ComponentInspecterInfoTile.cpp								\
				src/Components/InspecterSelecter/ComponentInspecterSelecter.cpp								\
				src/Components/InspecterSelecterGroup/ComponentInspecterSelecterGroup.cpp					\
				src/Components/InspecterSelecterGroupDraggable/ComponentInspecterSelecterGroupDraggable.cpp	\
				src/Components/Model3D/ComponentModel3D.cpp													\
				src/Components/Rectangle/ComponentRectangle.cpp												\
				src/Components/Ressources/ComponentRessources.cpp											\
				src/Components/RoundedRectangle/ComponentRoundedRectangle.cpp								\
				src/Components/Skybox/ComponentSkybox.cpp													\
				src/Components/SliderVolume/ComponentSliderVolume.cpp										\
				src/Components/Text/ComponentText.cpp														\
				src/Components/TextBox/ComponentTextBox.cpp 			 									\
				src/Components/TextGroup/ComponentTextGroup.cpp												\
				src/Components/TextGroupDraggable/ComponentTextGroupDraggable.cpp							\
				src/Components/TextMessage/ComponentTextMessage.cpp											\
				src/Components/Tile/ComponentTile.cpp														\
				src/Components/TileMap/ComponentTileMap.cpp													\
				src/Components/VolumeSection/ComponentVolumeSection.cpp										\
				src/Components/DelayServerSection/ComponentDelayServerSection.cpp							\
				src/Exceptions/Exceptions.cpp																\
				src/I18n/I18nHelper.cpp																		\
				src/Parsing/Parsing.cpp																		\
				src/Parsing/ParsingError.cpp																\
				src/Parsing/ParsingHelp.cpp																	\
				src/Raylib/ColorManager/ColorManager.cpp													\
				src/Raylib/FontManager/FontManager.cpp														\
				src/Raylib/ModelManager/ModelManager.cpp													\
				src/Raylib/Render/Render.cpp																\
				src/Raylib/TextureManager/TextureManager.cpp												\
				src/Raylib/View/View.cpp																	\
				src/Ressources/Eggs/Eggs.cpp																\
				src/Ressources/Players/Players.cpp															\
				src/Ressources/Ref/Ref.cpp																	\
				src/Ressources/Ressources/Ressources.cpp													\
				src/Ressources/TileRessources/TileRessources.cpp											\
				src/SceneManager/SceneManager.cpp															\
				src/Scenes/AScene/AScene.cpp																\
				src/Scenes/CreditScene/CreditScene.cpp														\
				src/Scenes/CreditScene/DisplayCreditScene/DisplayCreditScene.cpp							\
				src/Scenes/GameScene/GameScene.cpp															\
				src/Scenes/HelperScene/HelperScene.cpp														\
				src/Scenes/MenuScene/MenuScene.cpp															\
				src/Scenes/OptionScene/OptionScene.cpp														\
				src/Scenes/OptionScene/ResolutionOption/ResolutionOptionScene.cpp							\
				src/Scenes/OptionScene/SoundOption/SoundOptionScene.cpp										\
				src/Server/Server/Server.cpp																\
				src/Server/Mutex/Mutex.cpp																	\
				src/Server/Thread/Thread.cpp																\
				src/Server/Commands/Commands.cpp															\
				src/Server/SharedMemory/SharedMemory.cpp													\
				src/Sfml/SoundManager/SoundManager.cpp														\
				src/Utils/Path/Path.cpp																		\
				src/Utils/RelativePlayerPosition/RelativePlayerPosition.cpp									\
				src/Utils/Utils/Utils.cpp																	\
				tests/testsI18n/basicI18n.cpp																\
				tests/testsServer/testsCommands.cpp															\

OBJ 	= 	$(patsubst src/%.cpp,compiled_object/%.o,$(SRC))

TEST_OBJ	=	$(patsubst src/%.cpp,compiled_object/%.o,$(TEST_SRC))

RESET		= "\033[0m"
BLUE		= "\033[34m"
BOLD		= "\033[1m"
FBLUE		= "\033[94m"
FGREEN		= "\033[92m"
FRED		= "\033[91m"
FYELLOW		= "\033[93m"
GREEN		= "\033[32m"
PURPLE		= "\033[35m"
RED			= "\033[31m"
YELLOW		= "\033[33m"

BIN	=	"zappy_gui"

TEST_BIN	=	"unit_tests"

FLAGS	=	-Wall 				\
			-Wextra				\
			-Wfloat-equal 		\
			-Wundef 			\
			-Wcast-align		\
			-Wshadow			\
			-Wlogical-op		\
			-Wredundant-decls	\
			-std=c++20			\
			-O2

TEST_FLAGS	=	--coverage -lcriterion

INCLUDES	=	-I./includes										\
				-I./libs/includes									\
				-I./src												\
				-I./src/Components/0000/IComponent					\
				-I./src/Components/0000/AComponent					\
				-I./src/Components/Background2D						\
				-I./src/Components/Button							\
				-I./src/Components/ButtonClassic					\
				-I./src/Components/Chatbox							\
				-I./src/Components/Circle							\
				-I./src/Components/Cube								\
				-I./src/Components/Image							\
				-I./src/Components/Inspecter						\
				-I./src/Components/InspecterInfo					\
				-I./src/Components/InspecterInfoTile				\
				-I./src/Components/InspecterSelecter				\
				-I./src/Components/InspecterSelecterGroup			\
				-I./src/Components/InspecterSelecterGroupDraggable	\
				-I./src/Components/Model3D							\
				-I./src/Components/Rectangle						\
				-I./src/Components/Ressources						\
				-I./src/Components/RoundedRectangle					\
				-I./src/Components/Skybox							\
				-I./src/Components/SliderVolume						\
				-I./src/Components/Text								\
				-I./src/Components/TextBox							\
				-I./src/Components/TextGroup						\
				-I./src/Components/TextGroupDraggable				\
				-I./src/Components/TextMessage						\
				-I./src/Components/Tile								\
				-I./src/Components/TileMap							\
				-I./src/Components/VolumeSection					\
				-I./src/Components/DelayServerSection				\
				-I./src/Exceptions									\
				-I./src/I18n										\
				-I./src/Parsing										\
				-I./src/Raylib/ColorManager							\
				-I./src/Raylib/FontManager							\
				-I./src/Raylib/ModelManager							\
				-I./src/Raylib/Render								\
				-I./src/Raylib/TextureManager						\
				-I./src/Raylib/SoundManager							\
				-I./src/Raylib/View									\
				-I./src/Ressources/Eggs								\
				-I./src/Ressources/Players							\
				-I./src/Ressources/Ref								\
				-I./src/Ressources/Ressources						\
				-I./src/Ressources/TileRessources					\
				-I./src/SceneManager								\
				-I./src/Scenes/AScene								\
				-I./src/Scenes/CreditScene							\
				-I./src/Scenes/CreditScene/DisplayCreditScene   	\
				-I./src/Scenes/GameScene							\
				-I./src/Scenes/HelperScene							\
				-I./src/Scenes/IScene								\
				-I./src/Scenes/MenuScene							\
				-I./src/Scenes/OptionScene							\
				-I./src/Scenes/OptionScene/ResolutionOption 		\
				-I./src/Scenes/OptionScene/SoundOption      		\
				-I./src/Server/Server								\
				-I./src/Server/Mutex								\
				-I./src/Server/Thread								\
				-I./src/Server/Commands								\
				-I./src/Server/SharedMemory							\
				-I./src/Sfml/SoundManager							\
				-I./src/Utils/Path									\
				-I./src/Utils/RelativePlayerPosition				\
				-I./src/Utils/Utils									\

LIBS	=	-L./libs	\
			-lraylib 	\
			-lGL 		\
			-lm			\
			-lpthread	\
			-ldl		\
			-lrt		\
			-lX11		\
			-lsfml-audio

COMP	=	g++

all:	$(BIN)

$(BIN):	makeLibs $(OBJ)
	@echo $(BOLD)$(GREEN)"Objects Done\n\n"$(RESET)
	@echo $(BOLD)$(PURPLE)"Compiling $(BIN)..."$(RESET)
	@$(COMP) -o $(BIN) $(OBJ) $(FLAGS) $(INCLUDES) $(LIBS)
	@make ascii

$(TEST_BIN):	makeLibs $(TEST_OBJ)
	@echo $(BOLD)$(GREEN)"Objects Done\n\n"$(RESET)
	@echo $(BOLD)$(PURPLE)"Compiling $(TEST_BIN)..."$(RESET)
	@$(COMP) -o $(TEST_BIN) $(TEST_SRC) $(TEST_FLAGS) $(INCLUDES) $(LIBS)
	@make ascii

makeLibs:
	@if [ -n "$$(ls -A libs | grep -vE '(^includes$$|^Makefile$$)')" ]; then \
		echo $(BOLD)$(PURPLE)"Making Libs..."$(RESET); \
		make -C libs; \
		echo $(BOLD)$(GREEN)"Libs Done\n\n"$(RESET); \
	fi
	@echo $(BOLD)$(PURPLE)"Compiling objects..."$(RESET)

clean:
	@if [ -n "$$(ls -A libs | grep -vE '(^includes$$|^Makefile$$)')" ]; then \
		make -C libs clean; \
	fi
	@rm -rf compiled_object
	@rm -rf vgcore*

fclean: clean tests_fclean
	@if [ -n "$$(ls -A libs | grep -vE '(^includes$$|^Makefile$$)')" ]; then \
		make -C libs fclean; \
	fi
	@rm -rf $(BIN)
	@rm -rf $(TEST_BIN)

re: fclean all

compiled_object/%.o: src/%.cpp
	@mkdir -p $(@D)
	@$(COMP) $(FLAGS) $(INCLUDES) $(LIBS) -g3 -c -o $@ $<
	@echo $(GREEN)">> compiling $<"$(RESET)

tests_run:	$(TEST_BIN)
	@./$(TEST_BIN)
	@make tests_fclean

tests_clean:
	@rm -rf *.gcda
	@rm -rf *.gcno

tests_fclean: tests_clean
	@rm -rf $(TEST_BIN)

ascii:
	@echo $(BOLD)$(PURPLE)
	@echo "\n\n\t(„• ֊ •„)❤"
	@echo "\t┏━U━━━U━━━━━━━━━━━━━━━━━┓"
	@echo "\t  $(BIN) ready to be used"
	@echo "\t┗━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"
	@echo $(RESET)
