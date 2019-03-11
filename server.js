
const express = require('express')
const app = express()

app.use( express.static('public', {
  setHeaders: (res, path, stat) => {

    if (path.endsWith('.wasm')) {
      res.set('Content-Type', 'application/wasm')
    }
  }
}) )

app.listen( 2222, () => console.log('Server running on port 2222!') )
