# `read_file`

Read a file into an array of `Amino::String`. Each line of the file will be an item in the array

## Inputs

### `file_path`

The file path to read from

### `utf8_only`

Set to `false` if you wish to read any file, despite if it does not make sense to interpret it as UTF-8 text.

### `debug`

Print debug messages to the standard output

## Outputs

### `read_lines`

The lines of the file as Amino Strings. Each item in the array corresponds to one line from the file

### `success`

Whether the read process was successful or not

### `msg_if_failed`

An error message to report what went wrong