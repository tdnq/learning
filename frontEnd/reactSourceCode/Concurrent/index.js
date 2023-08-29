
'use strict';
function Hello() {
    return <h1>hello</h1>;
}



const domContainer = document.querySelector('#root');
let app = ReactDOM.createRoot(domContainer)
app.render(<Hello />);