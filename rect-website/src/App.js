import React from 'react';
import Navbar from './components/Navbar';
import './App.css';
import Home from './components/Home';
import { BrowserRouter as Router, Switch, Route } from 'react-router-dom';
import Services from './components/pages/Services';
import Products from './components/pages/Products';
import SignUp from './components/pages/SignUp';

function App() {
  return (
    <Router>    
    <Navbar/>
    <Switch>
    <Route path='/' exact component={Home} />
    <Route path='/services' exact component={Services} />
    <Route path='/products' component={Products} />
    <Route path='/sign-up' component={SignUp} />
    </Switch>
    </Router>  
  );
}

export default App;
