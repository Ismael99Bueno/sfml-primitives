#include "thick_line.hpp"

namespace prm
{
    thick_line::thick_line(const alg::vec2 &p1,
                           const alg::vec2 &p2,
                           const sf::Color &color1,
                           const sf::Color &color2,
                           const float thickness,
                           const bool rounded) : m_p1(p1),
                                                 m_p2(p2),
                                                 m_thickness(thickness),
                                                 m_color1(color1),
                                                 m_color2(color2),
                                                 m_rounded(rounded) {}
    thick_line::thick_line(const alg::vec2 &p1,
                           const alg::vec2 &p2,
                           const float thickness,
                           const sf::Color &color,
                           const bool rounded) : thick_line(p1,
                                                            p2,
                                                            color,
                                                            color,
                                                            thickness,
                                                            rounded) {}

    const alg::vec2 &thick_line::p1() const { return m_p1; }
    const alg::vec2 &thick_line::p2() const { return m_p2; }

    const sf::Color &thick_line::color1() const { return m_color1; }
    const sf::Color &thick_line::color2() const { return m_color2; }

    bool thick_line::rounded() const { return m_rounded; }
    void thick_line::rounded(const bool rounded) { m_rounded = rounded; }

    float thick_line::thickness() const { return m_thickness; }
    void thick_line::thickness(const float thickness) { m_thickness = thickness; }

    void thick_line::p1(const alg::vec2 &p1) { m_p1 = p1; }
    void thick_line::p2(const alg::vec2 &p2) { m_p2 = p2; }

    void thick_line::color1(const sf::Color &c1) { m_color1 = c1; }
    void thick_line::color2(const sf::Color &c2) { m_color2 = c2; }

    void thick_line::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        const alg::vec2 dir = (m_p2 - m_p1).normalized(),
                        offset = alg::vec2(-dir.y, dir.x) * m_thickness * 0.5f;

        sf::Vertex tline[4];
        const alg::vec2 p1 = m_p1 + offset, p2 = m_p2 + offset,
                        p3 = m_p2 - offset, p4 = m_p1 - offset;
        tline[0].position = VEC2_AS(p1);
        tline[1].position = VEC2_AS(p2);
        tline[2].position = VEC2_AS(p3);
        tline[3].position = VEC2_AS(p4);
        tline[0].color = m_color1;
        tline[1].color = m_color2;
        tline[2].color = m_color2;
        tline[3].color = m_color1;
        target.draw(tline, 4, sf::Quads, states);

        if (!m_rounded)
            return;

        const float r = 0.5f * m_thickness;
        sf::CircleShape start(r), end(r);
        start.setOrigin(r, r);
        start.setPosition(VEC2_AS(m_p1));
        start.setFillColor(m_color1);
        end.setOrigin(r, r);
        end.setPosition(VEC2_AS(m_p2));
        end.setFillColor(m_color2);
        target.draw(start);
        target.draw(end);
    }
}