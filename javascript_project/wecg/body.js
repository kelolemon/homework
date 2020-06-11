const player = function (location_x, location_y) {
    this.location_x = location_x;
    this.location_y = location_y;
};

player.prototype.Move_right = function () {
    this.location_x += 1
};

player.prototype.Move_left = function () {
    this.location_x -= 1
};

player.prototype.Move_up = function () {
    this.location_y += 1;
};

player.prototype.Move_down = function () {
    this.location_y -= 1;
};

