import React from 'react'
import CardItem from './CardItem';
import './Card.css'

function Cards() {
    return (
        <div className='cards'>
        <h1>Check out these EPIC Destinations!</h1>
        <div className='cards__container'>
          <div className='cards__wrapper'>
            <ul className='cards__items'>
              <CardItem
                src='images/img-9.jpg'
                text='Explore the hidden waterfall deep inside Sri Lanka'
                label='Adventure'
                path='/services'
              />

             <CardItem
              src='images/img-2.jpg'
              text='Get experiences in amazing beautiful beaches'
              label='Luxury'
              path='/services'
            />
          </ul>
          <ul className='cards__items'>
            <CardItem
              src='images/img-3.jpg'
              text='Taste amazing tea in beautiful plantaion in Sri Lanka'
              label='Mystery'
              path='/services'
            />
            <CardItem
              src='images/img-4.jpg'
              text='Experience traditional essence of the true Sri Lankan culture'
              label='Adventure'
              path='/products'
            />
            <CardItem
              src='images/img-8.jpg'
              text='Travel with Badulu kumari'
              label='Adrenaline'
              path='/sign-up'
            />

            </ul>
          </div>

        </div>
            
        </div>
    )
}

export default Cards
