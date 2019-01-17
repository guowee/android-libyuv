package com.missile.yuv.demo;

import android.app.ListActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class StartActivity extends ListActivity {
    private String[] mTitles = new String[]{
            MainActivity.class.getSimpleName(),
            TestActivity.class.getSimpleName()
    };
    private Class[] mActivities = new Class[]{
            MainActivity.class,
            TestActivity.class
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setListAdapter(new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, mTitles));
    }

    @Override
    protected void onListItemClick(ListView l, View v, int position, long id) {
        startActivity(new Intent(this, mActivities[position]));
    }

}
