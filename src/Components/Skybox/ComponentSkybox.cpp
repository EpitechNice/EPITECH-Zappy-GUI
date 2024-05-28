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
            Skybox::Skybox(std::string name, float size)
                : _size(size), _isDestroyed(false)
            {
                std::vector<std::string> textures = {
                    "assets/img/skybox/" + name + "/skyRenderSide1.png",
                    "assets/img/skybox/" + name + "/skyRenderSide2.png",
                    "assets/img/skybox/" + name + "/skyRenderSide3.png",
                    "assets/img/skybox/" + name + "/skyRenderSide4.png",
                    "assets/img/skybox/" + name + "/skyRenderBottom.png",
                    "assets/img/skybox/" + name + "/skyRenderTop.png",
                };
                std::vector<Vector3> positions = {
                    { 0, 0, _size / 2 },
                    { -_size / 2, 0, 0 },
                    { 0, 0, -_size / 2 },
                    { _size / 2, 0, 0 },
                    { 0, -_size / 2, 0 },
                    { 0, _size / 2, 0 },
                };
                std::vector<Vector3> rotations = {
                    { 90 * DEG2RAD, 0, 180 * DEG2RAD },
                    { 90 * DEG2RAD, 0, -90 * DEG2RAD},
                    { 90 * DEG2RAD, 0, 0 },
                    { 90 * DEG2RAD, 0, 90 * DEG2RAD},
                    { 0, 0, 0 },
                    { 180 * DEG2RAD, 0, 0 },
                };
                for (std::size_t i = 0; i < textures.size(); i++) {
                    Plane plane;
                    plane.texture = LoadTexture(textures[i].c_str());
                    plane.mesh = GenMeshPlane(_size, _size, 1, 1);
                    plane.model = LoadModelFromMesh(plane.mesh);
                    plane.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = plane.texture;
                    plane.position = positions[i];
                    plane.rotation = rotations[i];
                    plane.model.transform = MatrixRotateXYZ(plane.rotation);
                    plane.size = _size;
                    _planes.push_back(plane);
                }
            }

            Skybox::Skybox(Color color, float size)
                : _size(size), _isDestroyed(false)
            {
                std::vector<Vector3> positions = {
                    { 0, 0, _size / 2 },
                    { -_size / 2, 0, 0 },
                    { 0, 0, -_size / 2 },
                    { _size / 2, 0, 0 },
                    { 0, -_size / 2, 0 },
                    { 0, _size / 2, 0 },
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
                    plane.texture = LoadTextureFromImage(GenImageColor(1, 1, color));
                    plane.mesh = GenMeshPlane(_size, _size, 1, 1);
                    plane.model = LoadModelFromMesh(plane.mesh);
                    plane.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = plane.texture;
                    plane.position = positions[i];
                    plane.rotation = rotations[i];
                    plane.model.transform = MatrixRotateXYZ(plane.rotation);
                    plane.size = _size;
                    _planes.push_back(plane);
                }
            }

            void Skybox::destroy()
            {
                if (_isDestroyed)
                    return;
                for (auto &plane : _planes) {
                    UnloadTexture(plane.texture);
                    UnloadModel(plane.model);
                }
                _isDestroyed = true;
            }

            void Skybox::draw()
            {
                for (auto &plane : _planes) {
                    DrawModel(plane.model, plane.position, 1.0f, WHITE);
                }
            }

            void Skybox::update(std::shared_ptr<Zappy::GUI::Raylib::Render> render)
            {
                if (_isDestroyed)
                    return;
                Vector3 cameraPosition = render->view()->getPosition();
                Vector3 modify = { 0, 0, 0 };

                if (cameraPosition.y >= _size / 2) modify.y = -_size + 1;
                if (cameraPosition.y <= -_size / 2) modify.y = _size - 1;
                if (cameraPosition.x >= _size / 2) modify.x = -_size + 1;
                if (cameraPosition.x <= -_size / 2) modify.x = _size - 1;
                if (cameraPosition.z >= _size / 2) modify.z = -_size + 1;
                if (cameraPosition.z <= -_size / 2) modify.z = _size - 1;

                render->view()->modPosition(modify);
                render->view()->modTarget(modify);
            }
        }
    }
}
