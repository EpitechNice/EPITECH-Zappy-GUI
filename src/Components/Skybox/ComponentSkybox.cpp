/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentSkybox
*/

#include "ComponentSkybox.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Skybox::Skybox(bool visible, float size)
            {
                _visible = visible;
                std::vector<std::string> paths = {
                    std::string("skybox/purple/skyRenderSide1.png"),
                    std::string("skybox/purple/skyRenderSide2.png"),
                    std::string("skybox/purple/skyRenderSide3.png"),
                    std::string("skybox/purple/skyRenderSide4.png"),
                    std::string("skybox/purple/skyRenderBottom.png"),
                    std::string("skybox/purple/skyRenderTop.png"),
                };
                std::vector<Texture2D> textures;
                for (auto &path : paths)
                    textures.push_back(Zappy::GUI::Raylib::TextureManager::get()->getTexture(path)),
                _createSkybox(textures, size);
            }

            void Skybox::destroy()
            {
                if (_isDestroyed) return;
                for (auto &plane : _planes)
                    UnloadModel(plane.model);
                _isDestroyed = true;
            }

            void Skybox::draw()
            {
                if (!_visible) return;
                for (auto &plane : _planes)
                    DrawModel(plane.model, plane.position, 1.0f, WHITE);
            }

            void Skybox::update(std::shared_ptr<Zappy::GUI::Raylib::Render> render)
            {
                Vector3 cameraPosition = render->view()->getPosition();
                Vector3 modify = { 0, 0, 0 };

                if (cameraPosition.x >= _sizeX / 2) modify.x = -_sizeX + 5;
                if (cameraPosition.x <= -_sizeX / 2) modify.x = _sizeX - 5;
                if (cameraPosition.y >= _sizeY / 2) modify.y = -_sizeY + 5;
                if (cameraPosition.y <= -_sizeY / 2) modify.y = _sizeY - 5;
                if (cameraPosition.z >= _sizeZ / 2) modify.z = -_sizeZ + 5;
                if (cameraPosition.z <= -_sizeZ / 2) modify.z = _sizeZ - 5;

                render->view()->modPosition(modify);
                render->view()->modTarget(modify);
            }


            void Skybox::_createSkybox(std::vector<Texture2D> textures, float size)
            {
                _sizeX = size;
                _sizeY = size;
                _sizeZ = size;

                std::vector<Vector3> positions = {
                    { 0, 0, _sizeY / 2 },
                    { -_sizeX / 2, 0, 0 },
                    { 0, 0, -_sizeY / 2 },
                    { _sizeX / 2, 0, 0 },
                    { 0, -_sizeY / 2, 0 },
                    { 0, _sizeY / 2, 0 },
                };
                std::vector<Vector3> rotations = {
                    { 90 * DEG2RAD, 0, 180 * DEG2RAD },
                    { 90 * DEG2RAD, 0, -90 * DEG2RAD},
                    { 90 * DEG2RAD, 0, 0 },
                    { 90 * DEG2RAD, 0, 90 * DEG2RAD},
                    { 0, 0, 0 },
                    { 180 * DEG2RAD, 0, 0 },
                };
                for (std::size_t i = 0; i < positions.size(); i++) {
                    Plane plane;
                    plane.texture = textures[i];
                    plane.mesh = GenMeshPlane(_sizeX, _sizeY, 1, 1);
                    plane.model = LoadModelFromMesh(plane.mesh);
                    plane.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = plane.texture;
                    plane.position = positions[i];
                    plane.rotation = rotations[i];
                    plane.model.transform = MatrixRotateXYZ(plane.rotation);
                    _planes.push_back(plane);
                }
            }
        }
    }
}
