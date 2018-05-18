# bs-jszip


A set of Bucklescript bindings for [JSZip](https://react.semantic-ui.com). 

You can find a example usage of theses bindings in the ElpIDE project : [source](https://github.com/voodoos/ElpIDE/src/components/subcomponents/loadModal.re) || [demo](https://voodoos.github.io/ElpIDE/)

## Example usage

```
let readZip = f =>
      /* Locally open zip module */
      Zip.(
        create()
        /* Load from blob */
        |. loadAsync(`blob(f))
        |> Js.Promise.then_(zip => {
             zip
             |. forEach((_relativePath, zipEntry) =>
                    zipEntry
                    /* Read each file in zip */
                    |. Object.asyncString()
                    |> Js.Promise.then_(content => {
                         /* Do something */
                         Js.log(content);
                         Js.Promise.resolve(content);
                       })
                    |> ignore;
                );
             Js.Promise.resolve(zip);
           })
        |> ignore
);
```

## Introduction

These binding are not complete but in a very usable state. Please fill a issue or make a pull request if there are feature you miss !


## Installation
To use these bindings in an existing ReasonReact project simply add the repository to your dependencies :

```
yarn add "https://github.com/voodoos/bs-jszip"
```

And ask `bsb` to use it by adding `bs-jszip` to `bs-dependencies` in your `bsconfig.json`.

## Contributions

All contributions are welcomed.

## LICENSE

MIT (see LICENSE file for more details)