import logo from './logo.svg';
import './App.css';
import { lazy, Suspense } from "react";
const Index = lazy(() => import("./pages/index"));
const User = lazy(()=>import("./pages/user"));
function App() {
  return (
    <div className="App">
      <Suspense fallback="loading">
        <Index />
        <User name="td"/>
      </Suspense>
    </div>
  );
}

export default App;
