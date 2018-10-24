open Converters;

type cOptions;

type wOptions;

type loadOptions;

type asyncBlobOptions;

type asyncStringOptions;

type asyncUint8Options;

/* Utilities to build the options */
[@bs.obj]
external makeWriteOptionsAux:
  (
    ~base64: bool=?,
    ~binary: bool=?,
    ~date: Js.Date.t=?,
    ~compression: string=?,
    ~compressionOptions: cOptions=?,
    ~comment: string=?,
    ~optimizedBinaryString: bool=?,
    ~createFolders: bool=?,
    ~unixPermissions: int=?,
    ~dosPermissions: int=?,
    ~dir: bool=?,
    unit
  ) =>
  wOptions =
  "";

[@bs.obj]
external makeCompressionOptionsAux: (~level: int=?, unit) => cOptions = "";

let makeWriteOptions =
    (
      ~base64=?,
      ~binary=?,
      ~date=?,
      ~compression=?,
      ~compressionOptions=?,
      ~comment=?,
      ~optimizedBinaryString=?,
      ~createFolders=?,
      ~unixPermissions=?,
      ~dosPermissions=?,
      ~dir=?,
      (),
    ) =>
  makeWriteOptionsAux(
    ~base64?,
    ~binary?,
    ~date=?dateFromString(date),
    ~compression=?fromCompression(compression),
    ~compressionOptions?,
    ~comment?,
    ~optimizedBinaryString?,
    ~createFolders?,
    ~unixPermissions?,
    ~dosPermissions?,
    ~dir?,
    (),
  );

let makeCompressionOptions = lvl => makeCompressionOptionsAux(~level=lvl, ());

[@bs.obj]
external makeAsyncBlobOptionsAux:
  (
    ~_type: [@bs.as "blob"] _,
    ~compression: string=?,
    ~compressionOptions: cOptions=?,
    ~comment: string=?,
    ~mimeType: string=?,
    ~platform: string=?,
    ~encodeFileName: string => Js.Typed_array.Uint8Array.t=?,
    ~streamFiles: bool=?,
    ~createFolders: bool=?,
    unit
  ) =>
  asyncBlobOptions =
  "";

[@bs.obj]
external makeAsyncStringOptionsAux:
  (
    ~_type: [@bs.as "uint8array"] _,
    ~compression: string=?,
    ~compressionOptions: cOptions=?,
    ~comment: string=?,
    ~mimeType: string=?,
    ~platform: string=?,
    ~encodeFileName: string => Js.Typed_array.Uint8Array.t=?,
    ~streamFiles: bool=?,
    ~createFolders: bool=?,
    unit
  ) =>
  asyncStringOptions =
  "";

[@bs.obj]
external makeAsyncUint8OptionsAux:
  (
    ~_type: [@bs.as "uint8array"] _,
    ~compression: string=?,
    ~compressionOptions: cOptions=?,
    ~comment: string=?,
    ~mimeType: string=?,
    ~platform: string=?,
    ~encodeFileName: string => Js.Typed_array.Uint8Array.t=?,
    ~streamFiles: bool=?,
    ~createFolders: bool=?,
    unit
  ) =>
  asyncUint8Options =
  "";

let makeAsyncBlobOptions =
    /*~type_=?,*/
    (
      ~compression=?,
      ~compressionOptions=?,
      ~comment=?,
      ~mimeType=?,
      ~platform=?,
      ~encodeFileName=?,
      ~streamFiles=?,
      ~createFolders=?,
      (),
    ) =>
  makeAsyncBlobOptionsAux(
    ~compression=?fromCompression(compression),
    ~compressionOptions?,
    ~comment?,
    ~mimeType=?fromMimeTypes(mimeType),
    ~platform=?fromPlatforms(platform),
    ~encodeFileName?,
    ~streamFiles?,
    ~createFolders?,
    (),
  );

let makeAsyncStringOptions =
    /*~type_=?,*/
    (
      ~compression=?,
      ~compressionOptions=?,
      ~comment=?,
      ~mimeType=?,
      ~platform=?,
      ~encodeFileName=?,
      ~streamFiles=?,
      ~createFolders=?,
      (),
    ) =>
  makeAsyncStringOptionsAux(
    ~compression=?fromCompression(compression),
    ~compressionOptions?,
    ~comment?,
    ~mimeType=?fromMimeTypes(mimeType),
    ~platform=?fromPlatforms(platform),
    ~encodeFileName?,
    ~streamFiles?,
    ~createFolders?,
    (),
  );

let makeAsyncUint8Options =
    /*~type_=?,*/
    (
      ~compression=?,
      ~compressionOptions=?,
      ~comment=?,
      ~mimeType=?,
      ~platform=?,
      ~encodeFileName=?,
      ~streamFiles=?,
      ~createFolders=?,
      (),
    ) =>
  makeAsyncUint8OptionsAux(
    ~compression=?fromCompression(compression),
    ~compressionOptions?,
    ~comment?,
    ~mimeType=?fromMimeTypes(mimeType),
    ~platform=?fromPlatforms(platform),
    ~encodeFileName?,
    ~streamFiles?,
    ~createFolders?,
    (),
  );

[@bs.obj]
external makeLoadOptionsAux:
  (
    ~base64: bool=?,
    ~checkCRC32: bool=?,
    ~optimizedBinaryString: bool=?,
    ~createFolders: bool=?,
    ~decodeFileName: Js.Typed_array.Uint8Array.t => string=?,
    unit
  ) =>
  loadOptions =
  "";

let makeLoadOptions =
    (
      ~base64=?,
      ~checkCRC32=?,
      ~optimizedBinaryString=?,
      ~createFolders=?,
      ~decodeFileName=?,
      (),
    ) =>
  makeLoadOptionsAux(
    ~base64?,
    ~checkCRC32?,
    ~optimizedBinaryString?,
    ~createFolders?,
    ~decodeFileName?,
    (),
  );
