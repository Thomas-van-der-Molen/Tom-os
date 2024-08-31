
function kernel()
%disp("Hello from kernel")
if ~coder.target("MATLAB")
    coder.cinclude("tomos/msh_lib/mshlib.h")
end
colors={'black' 'blue' 'green' 'cyan' 'red' 'magenta' 'brown' 'light_grey' 'dark_grey' 'light_blue' 'light_green' 'light_cyan' 'light_red' 'light_magenta' 'light_brown' 'white'};
vga_color = colors;

[vga_width, vga_height,terminal_row,terminal_column,terminal_color,terminal_buffer] = terminal_initialize(vga_color);
%[vga_width,vga_height,terminal_row,terminal_column,terminal_color,terminal_buffer]
[terminal_column, terminal_row, terminal_buffer] = terminal_writestring('Hello from matlab kernel!',vga_width,vga_height,terminal_row,terminal_column,terminal_color,terminal_buffer);
end

function ret = vga_entry_color(fg, bg)
%disp("Hello from vga_entry_color")
ret = bitor(fg, bitshift(bg, 4));
ret = uint8(ret);
%whos ret b
end

function ret = vga_entry(uc, color)
%disp("Hello from vga_entry")
%uc = uint8(uc);
%uc = str2ascii(uc,1);
assert(isa(uc, "char"))
%color = uint8(color);
assert(isa(color,"uint8"))
ret = bitor(uint16(uc), bitshift(uint16(color),8));
%ret = uint16(ret);
assert(isa(ret,"uint16"))
end

function [vga_width,vga_height,terminal_row,terminal_column,terminal_color,terminal_buffer] = terminal_initialize(vga_color)
%disp("Hello from terminal_initialize")
vga_width = uint32(80);
vga_height = uint32(25);
terminal_row = uint32(0);
%terminal_column= uint32(0);
terminal_column=double(0);
terminal_color = vga_entry_color(find(vga_color=="light_grey")-1, find(vga_color=="black")-1);%always need -1 with arrays
terminal_color = uint8(terminal_color);
%terminal_buffer = uint16(vga_width * vga_height);
%terminal_buffer = createArray([1 vga_width*vga_height], "uint16");
terminal_buffer = zeros([1 vga_width*vga_height], "uint16");
for y=0:vga_height
    for x=0:vga_width
        if ~coder.target("MATLAB")
            index = (y*vga_width) + x;
            value = vga_entry(' ', terminal_color);
            coder.ceval("use_video_memory",uint32(index),uint16(value));
        end
    end
end

end

function terminal_buffer = terminal_putentryat(c, color, x, y,vga_width,terminal_buffer)
%disp("Hello from terminal_putentryat")
index = uint32(y * vga_width + x + 1);%+1 always needed
%terminal_buffer(x, y) = vga_entry(c, color);
%terminal_buffer(index) = vga_entry(c, color);
value = vga_entry(c, color);
if ~coder.target("MATLAB")
    coder.ceval("use_video_memory",uint32(index),uint16(value));
end
end

function [terminal_column,terminal_row, terminal_buffer] = terminal_putchar(c, vga_width,vga_height,terminal_row,terminal_column,terminal_color,terminal_buffer)
%disp("Hello from terminal_putchar")
terminal_buffer = terminal_putentryat(c, terminal_color, terminal_column, terminal_row,vga_width,terminal_buffer);
if terminal_column+1 == vga_width
    terminal_column = 0;
    if terminal_row+1 == vga_height
        terminal_row = uint32(0);
    else
        terminal_row = terminal_row+1;
    end
else
    %assert(isa(terminal_column,"uint32"))
    %whos terminal_column
    %terminal_columnType = class(terminal_column);
    %terminal_column = cast(terminal_column, "uint32")
    terminal_column = double(terminal_column+1);
    %terminal_column = uint32(terminal_column);
    %terminal_column = cast(terminal_column,"uint32")
    %what the fuck
    %whos terminal_column
end

end

function [terminal_column, terminal_row,terminal_buffer] = terminal_write(data, size,vga_width,vga_height,terminal_row,terminal_column,terminal_color,terminal_buffer)
%disp("Hello from terminal_write")
for i=1 : size
    [terminal_column,terminal_row,terminal_buffer]  = terminal_putchar(data(i),vga_width,vga_height,terminal_row,terminal_column,terminal_color,terminal_buffer);
end
end

function [terminal_column,terminal_row,terminal_buffer] = terminal_writestring(data, vga_width,vga_height,terminal_row,terminal_column,terminal_color,terminal_buffer)
assert(isa(data, "char"))
%[vga_width,vga_height,terminal_row,terminal_column,terminal_color,terminal_buffer]
[terminal_column, terminal_row,terminal_buffer] = terminal_write(data, length(data),vga_width,vga_height,terminal_row,terminal_column,terminal_color,terminal_buffer);
end

