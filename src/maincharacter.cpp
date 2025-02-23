#include "maincharacter.hpp"

static const float INITIAL_PLAYER_POS_Y = 1080 / 2 - 120;

void maincharacter::init()
{
    row = 5;
    col = 8;
    size = _data->_assets->getTexture(PENGUIN).getSize();
    p.setTexture(_data->_assets->getTexture(PENGUIN));
    p.setPosition(1920 / 2 + size.x / col, INITIAL_PLAYER_POS_Y);

    velocity.x = 0;
    velocity.y = 0;
    this->isFallen = false;
    this->size.x /= col;
    this->size.y /= row;

    p.setTextureRect(sf::IntRect(0, 1, size.x, size.y));

    // Set the initial view size to the size of the window
    camera.setSize(1920, 1080);

    if (p.getPosition().y >= 1080 / 2)
    {
        camera.setCenter(1920 / 2, INITIAL_PLAYER_POS_Y);
    }
    else
    {
        camera.setCenter(1920 / 2, p.getPosition().y);
    }

    // Set the initial view to the camera
    _data->_window->setView(camera);

    MAX_STAMINA = 200;
    mApressed = false;
    stamina = MAX_STAMINA;
    staminaRecoveryRate = 2;
    staminaDrainRate = 4;
    isMoving = false;
    staminaBarBackground.setSize(sf::Vector2f(102, 22)); // Plus border
    staminaBarBackground.setFillColor(sf::Color(50, 50, 50));
    staminaBarBackground.setPosition(10, 10);
    staminaBar.setSize(sf::Vector2f(100, 20)); // Full width for full stamina
    staminaBar.setFillColor(sf::Color(100, 250, 50));
    staminaBar.setPosition(11, 11); //
    movingLeft = false;
    movingRight = false;
    movingUp = false;
    movingDown = false;
    moveCamPos = p.getPosition();
}

maincharacter::maincharacter(data *data) : _data(data)
{
    movedDown = true;
    isDead = false;
}

void maincharacter::draw()
{

    //_data->_window->clear();

    _data->_window->draw(p);
    drawStaminaBar(*_data->_window);
    // _data->_window->display();
}

void maincharacter::move()
{
    bool moved = false;
    if (movingRight)
    {
        int xtexture = (p.getTextureRect().left + size.x) % (size.x * col);
        p.setTextureRect(sf::IntRect(xtexture, size.y * 2, size.x, size.y));
        if (p.getPosition().x < 1920 - size.x)
        {
            p.move(10, 0);
        }
        moved = true;
        movedDown = false;
    }
    else if (movingUp)
    {
        int xtexture = (p.getTextureRect().left + size.x) % (size.x * 4);
        p.setTextureRect(sf::IntRect(xtexture, size.y, size.x, size.y));
        p.move(0, -10);
        moved = true;
        movedDown = false;
    }
    else if (movingLeft)
    {
        int xtexture = (p.getTextureRect().left + size.x) % (size.x * col);
        p.setTextureRect(sf::IntRect(xtexture, size.y * 3, size.x, size.y));
        if (p.getPosition().x > 0)
        {
            p.move(-10, 0);
        }
        moved = true;
        movedDown = false;
    }
    else if (movingDown)
    {
        int xtexture = (p.getTextureRect().left + size.x) % (size.x * 4);
        p.setTextureRect(sf::IntRect(xtexture, size.y, size.x, size.y));
        p.move(0, 10);
        moved = true;
        movedDown = true;
    }

    isMoving = moved;
}

sf::Vector2f maincharacter::getPosition()
{
    return p.getPosition();
}

void maincharacter::setPosition(float x, float y)
{
    p.setPosition(x, y);
}
void maincharacter::processInput(sf ::Event event)
{
    // sf::Event event;
    // while(_data->_window->pollEvent(event))
    // {
    if (sf::Event::Closed == event.type)
    {
        _data->_window->close();
    }

    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Right:
            movingRight = true;
            break;
        case sf::Keyboard::Up:
            movingUp = true;
            break;
        case sf::Keyboard::Left:
            movingLeft = true;
            break;
        case sf::Keyboard::Down:
            movingDown = true;
            break;
        case sf::Keyboard::W:
            movingUp = true;
            break;
        case sf::Keyboard::A:
            movingLeft = true;
            break;
        case sf::Keyboard::S:
            movingDown = true;
            break;
        case sf::Keyboard::D:
            movingRight = true;
            break;
        }
    }

    // Handle the end of the movement
    else if (event.type == sf::Event::KeyReleased)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Right:
            movingRight = false;
            break;
        case sf::Keyboard::Up:
            movingUp = false;
            break;
        case sf::Keyboard::Left:
            movingLeft = false;
            break;
        case sf::Keyboard::Down:
            movingDown = false;
            break;
        case sf::Keyboard::W:
            movingUp = false;
            break;
        case sf::Keyboard::A:
            movingLeft = false;
            break;
        case sf::Keyboard::S:
            movingDown = false;
            break;
        case sf::Keyboard::D:
            movingRight = false;
            break;
        }
    }
}

void maincharacter::processMovedDown()
{
    sf::Vector2f playerPos = p.getPosition();
    float playerPosY = playerPos.y;

    sf::View currentView = _data->_window->getView();
    sf::Vector2f screenPosition = (sf::Vector2f)(_data->_window->mapCoordsToPixel(playerPos, currentView));

    if (playerPosY >= (playerPosY - screenPosition.y + _data->_window->getSize().y - p.getGlobalBounds().height - 15.f))
    {
        isDead = true;
        return;
    }

    if (movedDown == false || ((isMoving == false) && (p.getPosition().y <= INITIAL_PLAYER_POS_Y)))
    {
        if (playerPosY <= moveCamPos.y)
        {
            moveCamPos = playerPos;
            camera.setCenter(1920 / 2, playerPosY);
            _data->_window->setView(camera);
        }
    }
    else if ((isMoving == false) && (p.getPosition().y == INITIAL_PLAYER_POS_Y))
    {
        camera.setCenter(1920 / 2, INITIAL_PLAYER_POS_Y);
        _data->_window->setView(camera);
    }
}

void maincharacter::update()
{
    // Update the stamina first
    updateStamina();

    // Handle the fallen state
    if (stamina == 0 && !isFallen)
    {
        // Enter fallen state
        isFallen = true;
        moveCooldownTimer.restart();
        // Set the fallen texture
        p.setTextureRect(sf::IntRect(0, size.y * 4, size.x, size.y));
    }
    else if (isFallen && moveCooldownTimer.getElapsedTime().asSeconds() >= 1.0f)
    {
        // Recover from fallen state
        isFallen = false;
        // Set the stand up texture or reset to initial sprite state
        p.setTextureRect(sf::IntRect(0, 0, size.x, size.y)); // Replace with appropriate texture rect for standing up
    }

    // If the character has recovered from fallen, handle normal movement
    if (!isFallen)
    {
        move();
    }
    // Otherwise, ensure the character does not move
    else
    {
        // Additional logic for character in fallen state (if necessary)
    }

    processMovedDown();
}

void maincharacter::updateStamina()
{
    // std::cout << "Stamina: " << stamina << ", Up: " << movingUp << ", Left: " << movingLeft << ", Right: " << movingRight << ", Recovery: " << staminaRecoveryRate << ", Drain: " << staminaDrainRate << std::endl;

    if (!movingUp && !movingLeft && !movingRight && !movingDown || ((movingUp || movingLeft || movingRight || movingDown) && isFallen))
    {
        if (stamina + staminaRecoveryRate < MAX_STAMINA)
        {
            stamina += staminaRecoveryRate;
        }
        else
        {
            stamina = MAX_STAMINA;
        }
    }
    else
    {
        stamina = std::max(stamina - staminaDrainRate, 0.0f);
    }
    staminaBar.setPosition(getPosition().x, getPosition().y - 100);
    displayStamina();
}

sf::Vector2f maincharacter::getPosPlayer()
{
    return p.getPosition();
}

void maincharacter::displayStamina()
{
    float currentWidth = (static_cast<float>(stamina) / MAX_STAMINA) * 100;
    staminaBar.setSize(sf::Vector2f(currentWidth, staminaBar.getSize().y));
}

void maincharacter::drawStaminaBar(sf::RenderTarget &target) const
{
    // target.draw(staminaBarBackground);
    target.draw(staminaBar);
}

void maincharacter::setspeed(float speed)
{
    velocity.x = speed;
}

void maincharacter::setDeadTexture()
{
    p.setTextureRect(sf::IntRect(0, size.y * 4, size.x, size.y));
}

bool maincharacter::getIsDead()
{
    return isDead;
}

bool maincharacter::getIsMovedDown()
{
    return movedDown;
}

sf::Vector2f maincharacter::getMoveCamPos()
{
    return moveCamPos;
}

void maincharacter::setMoveCamPos(const sf::Vector2f &_moveCamPos)
{
    moveCamPos = _moveCamPos;
}