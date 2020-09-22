# cr-convert
A tool for converting files using the Cr only line ending.

Line ending conversion seems to be pretty focussed on converting between
unix style Lf line endings and windows style CrLf line endings. This
tool does not solve that problem, as it is already solved elsewhere.
For simplicity and convenience, we use unix style Line feeds as our 
target output, but we accept all three line endings as inputs.

Older systems, such as Mac OS Pre-9, and the Color Computer systems 
use a different line ending scheme, the Carriage Return by itself.

Typically the Cr in todays systems resets the cursor to the beginning
of the line, so you'll be able to see this issue coming to play if
when you try to display a file, you only end up seeing the last line.

Currently the tool is split up into two small utilities, 
both of which read from STDIN and write to STDOUT. From-Cr will output
unix style line feeds, and To-Cr will convert back to the Cr only
system.

There are a few flaws with the current system's simplicity. They
require input redirection to use, and cannot convert files in-place, due
to outputting immediately upon receiving input. These flaws will be solved
in future versions, but for now it is useful for our needs.

Usage:
To convert from a canonically MAC OS Pre-9 style Cr line ending to Unix style.

  from-cr \<InputFile \>TempFile

To convert from a unix style Lf line ending to the Cr line ending.

  to-cr \<InputFile \>TempFile

It is not recommended to use this tool as is in production systems,
as the format for its use is likely to change wildly as I improve it.
If you do decide to use it in your own tools, make sure that the method
of defining input, output, and the line ending style is as simple to
update as possible.

