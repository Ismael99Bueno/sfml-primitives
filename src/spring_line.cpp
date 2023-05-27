#include "prm/pch.hpp"
#include "prm/spring_line.hpp"
#include "prm/flat_line_strip.hpp"
#include "prm/flat_line.hpp"

namespace prm
{
spring_line::spring_line(const glm::vec2 &p1, const glm::vec2 &p2, const sf::Color &color)
    : m_p1(p1), m_p2(p2), m_color(color)
{
}

std::size_t spring_line::supports_count() const
{
    return m_supports_count;
}
float spring_line::supports_length() const
{
    return m_supports_length;
}
float spring_line::left_padding() const
{
    return m_left_padding;
}
float spring_line::right_padding() const
{
    return m_right_padding;
}
float spring_line::min_height() const
{
    return m_min_height;
}

void spring_line::supports_count(const std::size_t supports_count)
{
    m_supports_count = supports_count;
}
void spring_line::supports_length(const float supports_length)
{
    m_supports_length = supports_length;
}
void spring_line::left_padding(const float left_padding)
{
    m_left_padding = left_padding;
}
void spring_line::right_padding(const float right_padding)
{
    m_right_padding = right_padding;
}
void spring_line::min_height(const float min_height)
{
    m_min_height = min_height;
}

const glm::vec2 &spring_line::p1() const
{
    return m_p1;
}
const glm::vec2 &spring_line::p2() const
{
    return m_p2;
}

const sf::Color &spring_line::color() const
{
    return m_color;
}
void spring_line::color(const sf::Color &c)
{
    m_color = c;
}

void spring_line::p1(const glm::vec2 &p1)
{
    m_p1 = p1;
}
void spring_line::p2(const glm::vec2 &p2)
{
    m_p2 = p2;
}

void spring_line::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    flat_line fl(m_p1, m_p2, m_color);
    target.draw(fl, states);

    std::vector<glm::vec2> sp_line(1 + 4 * m_supports_count);
    const glm::vec2 segment = m_p2 - m_p1;
    const float base_length = (glm::length(segment) - m_left_padding - m_right_padding) / m_supports_count,
                angle = atan2f(segment.y, segment.x);

    glm::vec2 ref1 = m_p1 + glm::normalize(segment) * m_left_padding,
              ref2 = m_p2 - glm::normalize(segment) * m_right_padding;
    sp_line[0] = ref1;
    for (std::size_t i = 0; i < m_supports_count; i++)
    {
        const float y =
            sqrtf(std::max(m_min_height, m_supports_length * m_supports_length - base_length * base_length));
        const glm::vec2 side1 = glm::rotate(glm::vec2(0.5f * base_length, y), angle),
                        side2 = glm::rotate(glm::vec2(0.5f * base_length, -y), angle);

        const std::size_t idx1 = 1 + 2 * i, idx2 = 1 + 2 * m_supports_count + 2 * i;

        sp_line[idx1] = ref1 + side1;
        sp_line[idx1 + 1] = ref1 + side1 + side2;

        sp_line[idx2] = ref2 - side1;
        sp_line[idx2 + 1] = ref2 - side1 - side2;

        ref1 += side1 + side2;
        ref2 -= side1 + side2;
    }
    flat_line_strip fls(sp_line, m_color);
    target.draw(fls, states);
}
} // namespace prm