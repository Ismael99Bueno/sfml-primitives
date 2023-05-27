#ifndef THICK_LINE_STRIP_HPP
#define THICK_LINE_STRIP_HPP

#include "glm/vec2.hpp"
#include "cvw/container_view.hpp"
#include <SFML/Graphics.hpp>

namespace prm
{
class thick_line_strip : public sf::Drawable
{
  public:
    thick_line_strip(const sf::Color &color = sf::Color::White, float thickness = 10.f);
    thick_line_strip(const std::vector<glm::vec2> &points, const sf::Color &color = sf::Color::White,
                     float thickness = 10.f);

    void append(const glm::vec2 &point);
    void erase(std::size_t index);
    void erase(std::size_t from, std::size_t to);
    void clear();

    const sf::Color &color() const;

    const std::vector<std::pair<glm::vec2, sf::Color>> &vertices() const;
    cvw::vector<std::pair<glm::vec2, sf::Color>> vertices();

    void color(const sf::Color &color);
    void alpha(float alpha);

    float thickness() const;
    void thickness(float thickness);

  private:
    std::vector<std::pair<glm::vec2, sf::Color>> m_vertices;
    sf::Color m_color;
    float m_thickness;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
} // namespace prm

#endif