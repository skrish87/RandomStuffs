package com.kishore.gallery;

import android.app.ProgressDialog;
import android.content.Intent;
import android.graphics.drawable.Drawable;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.GridView;
import android.widget.Toast;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.StatusLine;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.json.JSONArray;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;


public class AlbumsActivity extends ActionBarActivity {

    ProgressDialog mProgressDialog;
    ArrayList<image> arraylist;
    GridView gv;
    ImageAdapter adapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_albums);
        try {
            new json().execute("http://kishore.cinemazz.com/json/Albums.aspx");
    } catch (Exception e) {
        e.printStackTrace();
    }
    }

    class json extends AsyncTask<String, Void, Void> {

        @Override
        protected void onPreExecute() {
            super.onPreExecute();
            mProgressDialog = new ProgressDialog(AlbumsActivity.this);
            mProgressDialog.setTitle("Albums");
            mProgressDialog.setMessage("Loading...");
            mProgressDialog.setIndeterminate(false);
            mProgressDialog.show();
        }

        public Void doInBackground(String... urls) {
            StringBuilder builder = new StringBuilder();
            HttpClient client = new DefaultHttpClient();
            HttpGet httpGet = new HttpGet(urls[0]);
            try {
                HttpResponse response = client.execute(httpGet);
                StatusLine statusLine = response.getStatusLine();
                int statusCode = statusLine.getStatusCode();
                if (statusCode == 200) {
                    HttpEntity entity = response.getEntity();
                    InputStream content = entity.getContent();
                    BufferedReader reader = new BufferedReader(new InputStreamReader(content));
                    String line;
                    while ((line = reader.readLine()) != null) {
                        builder.append(line);
                    }
                } else {
                    Log.e(json.class.toString(), "Failed to download file");
                }
            } catch (ClientProtocolException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
            String value = builder.toString();

            try {
                JSONObject json = new JSONObject(value);
                JSONArray jsonarray = json.getJSONArray("albums");
                arraylist = new ArrayList<image>();

                for (int i = 0; i < jsonarray.length(); i++) {
                    image map = new image();
                    json = jsonarray.getJSONObject(i);
                    map.id = json.getInt("id");
                    map.title = json.getString("title");
                    String url = json.getString("photourl");
                    try {
                        URL thumb_u = new URL(url);
                        map.photo = Drawable.createFromStream(thumb_u.openStream(), "src");
                    }
                    catch (Exception e) {
                        e.printStackTrace();
                    }
                    arraylist.add(map);
                }
                Log.i(AlbumsActivity.class.getName(), json.toString());
            } catch (Exception e) {
                e.printStackTrace();
            }
            return null;
        }

        protected void onPostExecute(Void value) {
            gv = (GridView) findViewById(R.id.albums_grid);
            adapter = new ImageAdapter(AlbumsActivity.this, arraylist);
            // Set the adapter to the ListView
            gv.setAdapter(adapter);
            gv.setOnItemClickListener(new AdapterView.OnItemClickListener() {
                @Override
                public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                    image a = arraylist.get(i);
                    Intent n = new Intent(getApplicationContext(), PhotosActivity.class);
                    n.putExtra("AlbumId", a.id);
                    n.putExtra("AlbumTitle", a.title);
                    startActivity(n);
                }
            });
            mProgressDialog.dismiss();
        }

    }
}
