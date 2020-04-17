int roll_dice(string **player_name, int &turn_count, int & No_of_sixes ){
  int dice_number;
  cout <<"Rolling the dice!"<<endl;
  srand(time(NULL));
  dice_number = rand()%6+1;
  if (dice_number == 6){
    cout << "6"<<endl<<endl;
    No_of_sixes++;
    if (No_of_sixes < 3){
      roll_dice(player_name, turn_count, No_of_sixes);
    }
    if (No_of_sixes==3){
      cout<< player_name[turn_count][0] << " lost his turn!"<<endl<<endl;
      No_of_sixes=0;
      return 0;
    }
  }
  cout << dice_number<< endl;
  return dice_number;
}
