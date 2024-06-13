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
			src/Exceptions/Exceptions.cpp																\
			src/I18n/I18nHelper.cpp																		\
			src/Parsing/Parsing.cpp																		\
			src/Parsing/ParsingError.cpp																\
			src/Parsing/ParsingHelp.cpp																	\
			src/Raylib/ColorManager/ColorManager.cpp													\
			src/Raylib/FontManager/FontManager.cpp														\
			src/Raylib/Render/Render.cpp																\
			src/Raylib/View/View.cpp																	\
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
			src/Sfml/SoundManager/SoundManager.cpp														\
			src/Utils/Utils/Utils.cpp																	\
			src/Utils/Mutex/Mutex.cpp																	\

OBJ 	= 	$(patsubst src/%.cpp,compiled_object/%.o,$(SRC))

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
				-I./src/Exceptions									\
				-I./src/I18n										\
				-I./src/Parsing										\
				-I./src/Raylib/ColorManager							\
				-I./src/Raylib/FontManager							\
				-I./src/Raylib/Render								\
				-I./src/Raylib/SoundManager							\
				-I./src/Raylib/View									\
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
				-I./src/Sfml/SoundManager							\
				-I./src/Utils/Utils									\
				-I./src/Utils/Mutex									\

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

fclean: clean
	@if [ -n "$$(ls -A libs | grep -vE '(^includes$$|^Makefile$$)')" ]; then \
		make -C libs fclean; \
	fi
	@rm -rf $(BIN)

re: fclean all

compiled_object/%.o: src/%.cpp
	@mkdir -p $(@D)
	@$(COMP) $(FLAGS) $(INCLUDES) $(LIBS) -g3 -c -o $@ $<
	@echo $(GREEN)">> compiling $<"$(RESET)


ascii:
	@echo $(BOLD)$(PURPLE)
	@echo "\n\n\t(„• ֊ •„)❤"
	@echo "\t┏━U━━━U━━━━━━━━━━━━━━━━━┓"
	@echo "\t  $(BIN) ready to be used"
	@echo "\t┗━━━━━━━━━━━━━━━━━━━━━━━┛\n\n"
	@echo $(RESET)
