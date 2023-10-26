#include <ButtonTable.hpp>


// Constructor ///////////////////////////////////////////////////////////////////////////////////////////////////

ButtonTable::ButtonTable()
{
}

void ButtonTable::create(unsigned int row, unsigned int col,
                         unsigned int w, unsigned int h,
                         unsigned int d_x, unsigned int d_y,
                         sf::Font &font, unsigned int fontsize)
{
    // Setup

    MAX_ROW = row;
    MAX_COL = col;
    MAX_CELL = row * col;
    width = w;
    height = h;
    Offset_x = d_x;
    Offset_y = d_y;
    numCell = 0;
    Fill = sf::Color::White;
    Cover = sf::Color(40, 40, 40, 255);
    Text = sf::Color::Black;
    sf::Color BackgroundColor = sf::Color(255, 255, 255, 255);

    // Background

    Texture.create(col * (w + Offset_x) - Offset_x, row * (h + Offset_y) - Offset_y);
    Texture.setSmooth(true);
    Background.setSize(sf::Vector2f(col * (w + Offset_x) - Offset_x, row * (h + Offset_y) - Offset_y));
    Background.setFillColor(BackgroundColor);

    // Table

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            Table[i * col + j].create(j * (w + Offset_x), i * (h + Offset_y), w, h, font, fontsize, "");
            Table[i * col + j].drawTexture();
            Table[i * col + j].setFillColor(Fill);
            Table[i * col + j].setCoverColor(Cover);
            Table[i * col + j].setTextColor(Text);
        }
}

// Draw //////////////////////////////////////////////////////////////////////////////////

void ButtonTable::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    sf::Sprite sprite(Texture.getTexture());
    sprite.setPosition(x, y);
    target.draw(sprite);
}

// Misc //////////////////////////////////////////////////////////////////////////////////

int ButtonTable::getHeight() const
{
    return (MAX_ROW * (height + Offset_y) - Offset_y);
}

sf::Vector2f ButtonTable::getPosition() const
{
    return sf::Vector2f(x, y);
}

void ButtonTable::setPosition(float a, float b)
{
    x = a;
    y = b;
    if (!Table.empty())
        for (int i = 0; i < MAX_CELL; i++)
            Table[i].setGlobalPosition(a, b);
}

bool ButtonTable::isPressed(sf::Event event)
{
    if (!Table.empty())
    {
        for (int i = 0; i < numCell; i++)
            Texture.draw(Table[i]);
        for (int i = 0; i < numCell; i++)
            if (Table[i].isPressed(event))
            {
                Choice = Table[i].getText();
                return true;
            }
    }
    return false;
}

sf::String ButtonTable::getText()
{
    return Choice;
}

void ButtonTable::setColString(unsigned int col, sf::String s)
{
    if (!Col)
        Col = new sf::String[MAX_COL];
    Col[col] = s;
}

void ButtonTable::setFillColor(sf::Color color)
{
    if (!Table.empty())
        for (int i = 0; i < MAX_CELL; i++)
            Table[i].setFillColor(color);
    else
        Fill = color;
}

void ButtonTable::setTextColor(sf::Color color)
{
    if (!Table.empty())
        for (int i = 0; i < MAX_CELL; i++)
            Table[i].setTextColor(color);
    else
        Text = color;
}

void ButtonTable::setCoverColor(sf::Color color)
{
    if (!Table.empty())
        for (int i = 0; i < MAX_CELL; i++)
            Table[i].setCoverColor(color);
    else
        Cover = color;
}

int ButtonTable::min(int x, int y)
{
    if (x < y)
        return x;
    return y;
}

// Destructor ///////////////////////////////////////////////////////////////////////////////////////////////////////////

ButtonTable::~ButtonTable()
{
}