# `write_file`

Write an array of `Amino::String` into a text file on disk. Each element in the array will be a line of the text file.

## Inputs

### `enable`

Whether to execute the node or not

### `file_path`

The file path to write to

### `overwrite`

Whether a file will be overwritten if it already exists on disk

### `dry_run`

Do everything the node does normally except to execute the file write. Useful in combo with the debug flag for testing/preventing accidental overwrites

### `debug`

Print debug messages to the standard output

## Outputs

### `write_lines`

The lines of the file as an array of Amino Strings. Each item in the array will be written to a new line in the text file

### `success`

Whether the write process was successful or not

### `msg_if_failed`

An error message to report what went wrong